#include <Models/Entities/Unemployed.h>

Unemployed::Unemployed(const std::string& name, Building& building, unsigned happiness, unsigned money, unsigned lifePoints)
	: Citizen(name, building, happiness, money, lifePoints) { }

void Unemployed::live(unsigned dateDay)
{
}

bool Unemployed::serialize(const std::string& fileName) const
{
	return false;
}

bool Unemployed::deserialize(const std::string& fileName) const
{
	return false;
}
