#include "Citizen.h"

Citizen::Citizen(const string name, const Profession& profession, const Building& building, unsigned happiness, unsigned money, int lifePoints)
{

}

Citizen::Citizen(const Citizen& other)
{
}

Citizen& Citizen::operator=(const Citizen& other)
{
	// TODO: insert return statement here
}

Citizen::~Citizen()
{
}

void Citizen::live()
{
}

void Citizen::setName(string name)
{
	name = string(name);
}

void Citizen::setHappiness(unsigned happiness)
{
	this->happiness = happiness;
}

void Citizen::setMoney(unsigned money)
{
	this->money = money;
}

void Citizen::setLifePoints(int lifePoints)
{
	this->lifePoints = lifePoints;
}

void Citizen::free()
{

}

void Citizen::copyFrom(const Citizen& other)
{
}
