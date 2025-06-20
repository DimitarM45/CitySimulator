#include <Services/Simulation.h>

#include <random>
#include <fstream>
#include <stdexcept>

#include <Models/Entities/DormBuilding.h>
#include <Models/Entities/ApartmentBuilding.h>
#include <Models/Entities/ModernBuilding.h>

namespace SimulationErrorMessages
{
	const std::string INVALID_CONFIGURATION_OPTION_ERROR_MESSAGE = "Invalid configuration option!";
	const std::string BUILDING_NOT_FOUND_ERROR_MESSAGE = "Building not found!";
	const std::string CITIZEN_NOT_FOUND_ERROR_MESSAGE = "Citizen not found!";
}

using namespace SimulationErrorMessages;

Simulation::Simulation()
	: wasSeeded(false), wasLoaded(false), currentDeadPeople(0), daysSinceStart(0), states(), buildingSeeder(), buildings(0, 0) {
}

Simulation::Simulation(const Simulation& other)
	: states(), buildings(other.buildings.getLength(), other.buildings.getWidth()), buildingSeeder(other.buildingSeeder)
{
	copyFrom(other);
}

Simulation& Simulation::operator=(const Simulation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Simulation::~Simulation()
{
	free();
}

void Simulation::free()
{
	unsigned length = buildings.getLength();
	unsigned width = buildings.getWidth();

	for (size_t y = 0; y < length; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			delete buildings[y][x];
		}
	}
}

void Simulation::seed(unsigned length, unsigned width)
{
	free();

	buildings = Matrix<Building*>(length, width);

	CitizenSeeder citizenSeeder;

	buildingSeeder = BuildingSeeder(&citizenSeeder);

	for (size_t y = 0; y < length; y++)
	{
		for (size_t x = 0; x < length; x++)
		{
			Building* building = buildingSeeder.getRandom(y, x);

			Building* seederBuilding = buildings[y][x] = building;

			citizenSeeder.setBuilding(*seederBuilding);

			buildings[y][x]->seedCitizens();
		}
	}

	date = Date();
	wasSeeded = true;
	wasLoaded = false;
}

void Simulation::executeSteps(int steps)
{
	if (steps < 0)
	{
		if (states.size() < steps)
			return;

		int absSteps = steps * -1;
		Simulation simulation = states.at(states.size() - absSteps - 1);

		for (size_t i = 0; i < absSteps; i++)
		{
			states.pop_back();
		};

		copyFrom(simulation);
	}
	else if (steps > 0)
	{
		for (size_t i = 0; i < steps; i++)
		{
			states.push_back(Simulation(*this));

			std::vector<Building*> buildings = city.getBuildings();
			unsigned buildingCount = buildings.size();

			for (size_t i = 0; i < buildingCount; i++)
			{
				buildings[i]->passDay(date.getDay());
			}

			date++;
			daysSinceStart++;
		}
	}
}

Matrix<Building*>& Simulation::getBuildings()
{
	return buildings;
}

Building* Simulation::getBuilding(unsigned yIndex, unsigned xIndex)
{
	try
	{
		return buildings[yIndex][xIndex];
	}
	catch (...)
	{
		return nullptr;
	}
}

bool Simulation::addCitizen(unsigned yIndex, unsigned xIndex, Citizen& denizen)
{
	Building* building = city.getBuilding(yIndex, xIndex);

	if (!building)
		return false;

	return building->addCitizen(denizen);
}

bool Simulation::removeCitizen(unsigned yIndex, unsigned xIndex, const std::string& name)
{
	Building* building = city.getBuilding(yIndex, xIndex);

	if (!building)
		return false;

	return building->removeCitizen(name);
}

const std::string Simulation::getAllInfo() const
{
	unsigned length = buildings.getLength();
	unsigned width = buildings.getWidth();

	std::string infoString;

	for (size_t y = 0; y < length; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			infoString.append(buildings[y][x]->getInfoString());
			infoString.append("\n");
		}
	}

	infoString.pop_back();

	return infoString;
}

const std::string Simulation::getBuildingInfo(unsigned yIndex, unsigned xIndex)
{
	Building* building = getBuilding(yIndex, xIndex);

	if (!building)
		return BUILDING_NOT_FOUND_ERROR_MESSAGE;

	return building->getInfoString();
}

const std::string Simulation::getCitizenInfo(unsigned yIndex, unsigned xIndex, const std::string& citizenName)
{
	Building* building = getBuilding(yIndex, xIndex);

	if (!building)
		return BUILDING_NOT_FOUND_ERROR_MESSAGE;

	Citizen* citizen = building->getCitizen(citizenName);

	if (!citizen)
		return CITIZEN_NOT_FOUND_ERROR_MESSAGE;

	return citizen->getInfoString();
}

bool Simulation::serialize(const std::string& fileName) const
{
	std::ofstream outStream;

	outStream.open(fileName, std::ios::binary);

	if (!outStream.is_open())
		return false;

	int statesSize = states.size();

	outStream.write(reinterpret_cast<const char*>(&statesSize), sizeof(statesSize));

	for (size_t i = 0; i < statesSize; i++)
	{
		outStream.write(reinterpret_cast<const char*>(&states[i].date), sizeof(Date));
		outStream.write(reinterpret_cast<const char*>(&states[i].currentDeadPeople), sizeof(&states[i].currentDeadPeople));
		outStream.write(reinterpret_cast<const char*>(&states[i].daysSinceStart), sizeof(&states[i].daysSinceStart));
		outStream.write(reinterpret_cast<const char*>(&states[i].wasSeeded), sizeof(&states[i].wasSeeded));
		outStream.write(reinterpret_cast<const char*>(&states[i].wasLoaded), sizeof(&states[i].wasLoaded));


	}

	outStream.write(reinterpret_cast<const char*>(&date), sizeof(Date));
	outStream.write(reinterpret_cast<const char*>(&currentDeadPeople), sizeof(currentDeadPeople));
	outStream.write(reinterpret_cast<const char*>(&daysSinceStart), sizeof(daysSinceStart));
	outStream.write(reinterpret_cast<const char*>(&wasSeeded), sizeof(wasSeeded));
	outStream.write(reinterpret_cast<const char*>(&wasLoaded), sizeof(wasLoaded));

	outStream.close();

	return outStream.good();
}

bool Simulation::deserialize(const std::string& fileName)
{
	free();

	std::ifstream inStream;

	inStream.open(fileName, std::ios::binary);

	if (!inStream.is_open())
		return false;

	int statesSize = 0;

	inStream.read(reinterpret_cast<char*>(&statesSize), sizeof(statesSize));

	states = std::vector<Simulation>(statesSize);

	for (size_t i = 0; i < statesSize; i++)
	{
		inStream.read(reinterpret_cast<char*>(&states[i].date), sizeof(Date));
		inStream.read(reinterpret_cast<char*>(&states[i].currentDeadPeople), sizeof(&states[i].currentDeadPeople));
		inStream.read(reinterpret_cast<char*>(&states[i].daysSinceStart), sizeof(&states[i].daysSinceStart));
		inStream.read(reinterpret_cast<char*>(&states[i].wasSeeded), sizeof(&states[i].wasSeeded));
		inStream.read(reinterpret_cast<char*>(&states[i].wasLoaded), sizeof(&states[i].wasLoaded));
	}

	inStream.read(reinterpret_cast<char*>(&date), sizeof(Date));
	inStream.read(reinterpret_cast<char*>(&currentDeadPeople), sizeof(currentDeadPeople));
	inStream.read(reinterpret_cast<char*>(&daysSinceStart), sizeof(daysSinceStart));
	inStream.read(reinterpret_cast<char*>(&wasSeeded), sizeof(wasSeeded));
	inStream.read(reinterpret_cast<char*>(&wasLoaded), sizeof(wasLoaded));

	inStream.close();

	bool isStreamGood = inStream.good();

	if (isStreamGood)
	{
		wasLoaded = true;
		wasSeeded = false;
	}

	return isStreamGood;
}

bool Simulation::getWasSeeded() const
{
	return wasSeeded;
}

bool Simulation::getWasLoaded() const
{
	return wasLoaded;
}

unsigned Simulation::getDeadPeopleCount()
{
	unsigned length = city.getLength();
	unsigned width = city.getWidth();

	unsigned deadPeopleCount = 0;

	std::vector<Building*> buildings = city.getBuildings();

	for (size_t i = 0; i < length; i++)
	{
		std::vector<Citizen> denizens = buildings[i]->getDenizens();
		unsigned size = denizens.size();

		for (size_t i = 0; i < size; i++)
		{
			if (denizens[i].getHappiness() == 0 &&
				denizens[i].getMoney() == 0 &&
				denizens[i].getLifePoints() == 0)
			{
				deadPeopleCount++;
			}
		}
	}

	return deadPeopleCount;
}

Date Simulation::getDate() const
{
	return date;
}

void Simulation::copyFrom(const Simulation& other)
{
	buildings = other.buildings;
	date = other.date;
	currentDeadPeople = other.currentDeadPeople;
	daysSinceStart = other.daysSinceStart;
	wasSeeded = other.wasSeeded;
	wasLoaded = other.wasLoaded;
}
