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
	const std::string INVALID_HAPPINESS_ERROR_MESSAGE = "Cannot instantiate a citizen with 0 happiness!";
	const std::string INVALID_MONEY_ERROR_MESSAGE = "Cannot instantiate a citizen with 0 or negative money!";
	const std::string INVALID_LIFE_POINTS_ERROR_MESSAGE = "Cannot instantiate a citizen with 0 life points!";
	const std::string INVALID_NAME_ERROR_MESSAGE = "Cannot instantiate a citizen with an empty name!";
	const std::string INVALID_PROFESSION_ERROR_MESSAGE = "No such profession!";
}

using namespace CitizenErrorMessages;

Citizen::Citizen(const std::string& name, Building& building, ProfessionType professionType, unsigned happiness, unsigned money, unsigned lifePoints)
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

const std::string& Citizen::getName() const
{
	return name;
}

unsigned Citizen::getHappiness() const
{
	return status.happiness;
}

unsigned Citizen::getMoney() const
{
	return status.money;
}

unsigned Citizen::getLifePoints() const
{
	return status.lifePoints;
}

void Citizen::setName(const std::string& name)
{
	if (name.empty())
		throw std::invalid_argument(INVALID_NAME_ERROR_MESSAGE);

	this->name = name;
}

void Citizen::setHappiness(unsigned happiness)
{
	if (happiness == 0)
		throw std::invalid_argument(INVALID_HAPPINESS_ERROR_MESSAGE);

	this->happiness = happiness;
}

void Citizen::setMoney(unsigned money)
{
	this->money = money;
}

void Citizen::setLifePoints(unsigned lifePoints)
{
	if (lifePoints == 0)
		throw std::invalid_argument(INVALID_LIFE_POINTS_ERROR_MESSAGE);

	this->lifePoints = lifePoints;
}

void Citizen::setProfession(ProfessionType professionType)
{
	switch (professionType)
	{
	case ProfessionType::Teacher:
		profession = new Teacher();
		break;

	case ProfessionType::Miner:
		profession = new Miner();
		break;

	case ProfessionType::Programmer:
		profession = new Programmer();
		break;

	case ProfessionType::Unemployed:
		profession = new Unemployed();
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
	Profession* tempProfession = other.profession->clone();

	profession = tempProfession;
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
