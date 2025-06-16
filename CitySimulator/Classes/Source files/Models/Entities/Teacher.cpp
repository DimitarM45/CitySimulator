#include <Models/Entities/Teacher.h>

Teacher::Teacher(const std::string& name, Building& building, unsigned happiness, unsigned money, unsigned lifePoints)
	: Citizen(name, building, happiness, money, lifePoints) { }

void Teacher::live(unsigned dateDay)
{

}

bool Teacher::serialize(const std::string& fileName) const
{
	return false;
}

bool Teacher::deserialize(const std::string& fileName) const
{
	return false;
}
