#include <Models/Entities/ModernBuilding.h>

constexpr unsigned MODERN_DEFAULT_RENT = 1000;

ModernBuilding::ModernBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex, const CitizenSeeder& citizenSeeder)
	: Building(denizenCapacity, yIndex, xIndex, MODERN_DEFAULT_RENT, citizenSeeder) { }

std::string ModernBuilding::getInfoString(const std::string* name) const
{
	if (name)
		return Building::getInfoString(name);

	std::string infoString("Location " + std::to_string(yIndex) + " " + std::to_string(xIndex) + "\n");

	std::string infoString("\tType: modern\n");

	return infoString.append(Building::getInfoString());
}

bool ModernBuilding::serialize(const std::string& fileName) const
{
	return false;
}

bool ModernBuilding::deserialize(const std::string& fileName) const
{
	return false;
}
