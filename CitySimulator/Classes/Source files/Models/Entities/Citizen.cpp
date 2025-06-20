#include <string>
#include <iostream>
#include <stdexcept>

#include <Models/Entities/Citizen.h>

#include <Models/Entities/Miner.h>
#include <Models/Entities/Teacher.h>
#include <Models/Entities/Programmer.h>
#include <Models/Entities/Unemployed.h>

namespace CitizenErrorMessages
{
	const std::string INVALID_HAPPINESS_ERROR_MESSAGE = "Citizen happiness cannot be a negative value!";
	const std::string INVALID_MONEY_ERROR_MESSAGE = "Citizen money cannot be a negative value!";
	const std::string INVALID_LIFE_POINTS_ERROR_MESSAGE = "Citizen life points cannot be a negative value!";
	const std::string INVALID_NAME_ERROR_MESSAGE = "Cannot instantiate a citizen with an empty name!";
	const std::string INVALID_PROFESSION_ERROR_MESSAGE = "No such profession!";
}

namespace CitizenConstants
{
	constexpr unsigned DEFAULT_FOOD_PRICE = 50;
}

using namespace CitizenErrorMessages;
using namespace CitizenConstants;

Citizen::Citizen(const std::string& name, Building& building, ProfessionType professionType, int happiness, int money, int lifePoints)
	: building(building)
{
	setName(name);
	setMoney(money);
	setHappiness(happiness);
	setLifePoints(lifePoints);
	setProfession(professionType);
}

Citizen::Citizen(const Citizen& other)
	: building(other.building)
{
	copyFrom(other);
}

Citizen& Citizen::operator=(const Citizen& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Citizen::~Citizen()
{
	free();
}

void Citizen::live(unsigned dateDay)
{
	int moneyAfterRent = status.money - building.getRent() < 0;

	if (dateDay == 1)
	{
		profession->work();

		status.money -= building.getRent();
	}

	status.money -= DEFAULT_FOOD_PRICE;

	if (status.money < 0)
		status.money = 0;

	statuses.push_back(status);
}

const std::string& Citizen::getName() const
{
	return name;
}

int Citizen::getHappiness() const
{
	return status.happiness;
}

int Citizen::getMoney() const
{
	return status.money;
}

int Citizen::getLifePoints() const
{
	return status.lifePoints;
}

void Citizen::setName(const std::string& name)
{
	if (name.empty())
		throw std::invalid_argument(INVALID_NAME_ERROR_MESSAGE);

	this->name = name;
}

void Citizen::setHappiness(int happiness)
{
	if (happiness < 0)
		throw std::invalid_argument(INVALID_HAPPINESS_ERROR_MESSAGE);

	status.happiness = happiness;
}

void Citizen::setMoney(int money)
{
	if (money < 0)
		throw std::invalid_argument(INVALID_MONEY_ERROR_MESSAGE);

	status.money = money;
}

void Citizen::setLifePoints(int lifePoints)
{
	if (lifePoints < 0)
		throw std::invalid_argument(INVALID_LIFE_POINTS_ERROR_MESSAGE);

	status.lifePoints = lifePoints;
}

const std::string Citizen::getInfoString() const
{
	std::vector<Status> statuses;

	std::string infoString("Name: " + name + "\n");

	infoString.append("\tProfession: " + profession->getInfoString() + "\n");
	infoString.append("\tCurrent stats:\n");
	infoString.append("\t\tHappiness: " + std::to_string(status.happiness) + "\n");
	infoString.append("\t\tMoney: " + std::to_string(status.money) + "\n");
	infoString.append("\t\tLife Points: " + std::to_string(status.lifePoints) + "\n");
	infoString.append("\tHistory:\n");

	for (size_t i = 0; i < statuses.size(); i++)
	{
		infoString.append("\t\tH: " + std::to_string(statuses[i].happiness) + "\n");
		infoString.append("\t\tM: " + std::to_string(statuses[i].money) + "\n");
		infoString.append("\t\tLP: " + std::to_string(statuses[i].lifePoints) + "\n\n");
	}

	return infoString;
}

void Citizen::setProfession(ProfessionType professionType)
{
	switch (professionType)
	{
	case ProfessionType::Teacher:
		profession = new Teacher(*this);
		break;

	case ProfessionType::Miner:
		profession = new Miner(*this);
		break;

	case ProfessionType::Programmer:
		profession = new Programmer(*this);
		break;

	case ProfessionType::Unemployed:
		profession = new Unemployed(*this);
		break;

	default:
		throw std::invalid_argument(INVALID_PROFESSION_ERROR_MESSAGE);
	}
}

void Citizen::free()
{
	delete profession;
}

void Citizen::copyFrom(const Citizen& other)
{	
	Profession* profession = other.profession->clone(*this);

	this->profession = profession;
	name = other.name;
	building = other.building;
	status = other.status;
	statuses = other.statuses;
}

bool Citizen::serialize(const std::string& fileName) const
{
	return false;
}

bool Citizen::deserialize(const std::string& fileName) const
{
	return Citizen();
}
