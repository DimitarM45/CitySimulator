#include "../Header files/Programmer.h"
#include "Programmer.h"

Programmer::Programmer(const std::string& name, Building& building, unsigned happiness, double money, unsigned lifePoints)
	: Citizen(name, building, happiness, money, lifePoints)
{

}

void Programmer::live(unsigned dateDay)
{

}

bool Programmer::serialize(const std::string& fileName) const
{
	return false;
}

bool Programmer::deserialize(const std::string& fileName) const
{
	return false;
}
