#include <cmath>
#include <stdexcept>
#include <string>

#include <Models/Entities/Building.h>

namespace BuildingErrorMessages
{
	const std::string INVALID_CITIZEN_CAPACITY = "Building capacity cannot exceed " + BuildingConstants::MAX_CITIZEN_CAPACITY + '!';
}

Building::Building(unsigned citizenCapacity, unsigned yIndex, unsigned xIndex, unsigned rent, const CitizenSeeder& citizenSeeder)
	: citizenSeeder(citizenSeeder), yIndex(yIndex), xIndex(xIndex)
{
	this->isCentral = isCentralBuilding(yIndex, xIndex);
	setRent(rent);
	setCitizenCapacity(citizenCapacity);
}

Building::Building(const Building& other)
	: citizenSeeder(other.citizenSeeder)
{
	copyFrom(other);
}

Building& Building::operator=(const Building& other)
{
	if (this != &other)
		copyFrom(other);

	return *this;
}

void Building::passDay(unsigned day)
{
	unsigned denizenCount = citizens.size();

	for (size_t i = 0; i < denizenCount; i++)
	{
		citizens[i].live(day);
	}
}

unsigned Building::getRent() const
{
	return rent;
}

bool Building::getIsCentral() const
{
	return isCentral;
}

const std::string Building::getInfoString(const std::string* citizenName) const
{
	std::string infoString;

	if (citizenName)
	{
		for (size_t i = 0; i < citizens.size(); i++)
		{
			if (citizens[i].getName() == *citizenName)
				return infoString.append(citizens[i].getInfoString() + "\n");
		}
	}

	infoString.append("\tRent: " + std::to_string(rent) + "\n");
	infoString.append("\tCitizen count: " + std::to_string(citizens.size()) + "\n");
	infoString.append("\tCitizen capacity: " + std::to_string(citizenCapacity) + "\n");
	infoString.append("\tCentral: ").append(isCentral ? "true\n" : "false\n");
	infoString.append("\tDenizens: \n");

	for (size_t i = 0; i < citizens.size(); i++)
		infoString.append("\t\t" + citizens[i].getName() + "\n");

	return infoString;
}

Citizen* Building::getCitizen(const std::string& name)
{
	unsigned denizenCount = citizens.size();

	for (size_t i = 0; i < denizenCount; i++)
	{
		if (citizens[i].getName() == name)
			return &citizens[i];
	}

	return nullptr;
}

std::vector<Citizen>& Building::getCitizens()
{
	return citizens;
}

void Building::seedCitizens()
{
	int citizensCount = rand() % citizenCapacity + 1;

	for (size_t i = 0; i < citizensCount; i++)
	{
		Citizen* randomCitizen = citizenSeeder.getRandom();

		citizens[i] = Citizen(*randomCitizen);

		delete randomCitizen;
	}
}

bool Building::addCitizen(Citizen& citizen)
{
	if (citizens.size() == citizenCapacity)
		return false;

	citizens.push_back(citizen);

	return true;
}

bool Building::removeCitizen(const std::string& name)
{
	unsigned citizenCount = citizens.size();

	for (size_t i = 0; i < citizenCount; i++)
	{
		if (citizens[i].getName() == name)
		{
			citizens.erase(citizens.begin() + i);

			return true;
		}
	}

	return false;
}

void Building::setCitizenCapacity(unsigned citizenCapacity)
{
	using namespace BuildingConstants;

	if (citizenCapacity > MAX_CITIZEN_CAPACITY)
		throw std::invalid_argument(BuildingErrorMessages::INVALID_CITIZEN_CAPACITY);

	this->citizenCapacity = citizenCapacity;
}

void Building::setRent(unsigned rent)
{
	using namespace BuildingConstants;

	if (isCentral)
		rent *= CENTRAL_RENT_MULTIPLIER;

	else
		rent -= rent * SUBURBAN_RENT_MULTIPLIER;
}

bool Building::isCentralBuilding(unsigned xIndex, unsigned yIndex)
{

}

void Building::copyFrom(const Building& other)
{
	this->citizens = other.citizens;
	this->rent = other.rent;
	this->yIndex = other.yIndex;
	this->xIndex = other.xIndex;
	this->citizenCapacity = other.citizenCapacity;
	this->isCentral = other.isCentral;
}

bool Building::serialize(const std::string& fileName) const
{

}

bool Building::deserialize(const std::string& fileName) const
{
	return false;
}
