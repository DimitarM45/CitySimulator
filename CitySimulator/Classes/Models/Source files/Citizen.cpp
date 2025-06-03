#include "../Header files/Citizen.h"

#include <stdexcept>

namespace CitizenErrorMessages
{
	const char* INVALID_PROFESSION = "Invalid profession!";
}

Citizen::Citizen(const string& name, Building& building, unsigned happiness, unsigned money, int lifePoints)
	: happiness(happiness), money(money), lifePoints(lifePoints), building(building)
{
	this->name = name;
}

void Citizen::live()
{

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

int getRandomInRange(int min, int max)
{
	int range = max - min + 1;

	return min + (std::rand() % range);	
}
