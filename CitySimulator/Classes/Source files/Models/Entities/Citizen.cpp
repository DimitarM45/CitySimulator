#include <string>
#include <iostream>
#include <stdexcept>
#include <Models/Entities/Citizen.h>

namespace CitizenErrorMessages
{
	const std::string INVALID_HAPPINESS_ERROR_MESSAGE = "Cannot instantiate a citizen with 0 happiness!";
	const std::string INVALID_MONEY_ERROR_MESSAGE = "Cannot instantiate a citizen with 0 or negative money!";
	const std::string INVALID_LIFE_POINTS_ERROR_MESSAGE = "Cannot instantiate a citizen with 0 life points!";
	const std::string INVALID_NAME_ERROR_MESSAGE = "Cannot instantiate a citizen with an empty name!";
}

using namespace CitizenErrorMessages;

Citizen::Citizen(const std::string& name, Building& building, unsigned happiness, unsigned money, unsigned lifePoints)
	: building(building)
{
	this->name = name;
	
	setHappiness(happiness);
	setMoney(money);
	setLifePoints(lifePoints);
}

const std::string& Citizen::getName() const
{
	return name;
}

unsigned Citizen::getHappiness() const
{
	return happiness;
}

unsigned Citizen::getMoney() const
{
	return money;
}

unsigned Citizen::getLifePoints() const
{
	return lifePoints;
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

bool Citizen::serialize(const std::string& fileName) const
{
	return false;
}

bool Citizen::deserialize(const std::string& fileName) const
{
	return Citizen();
}

std::ostream& Citizen::operator<<(std::ostream& out)
{
	return out << "Name: " << this->getName()
		<< "\nHappiness: " << this->getHappiness()
		<< "\nMoney: " << this->getMoney()
		<< "\nLife points: " << this->getLifePoints();
}
