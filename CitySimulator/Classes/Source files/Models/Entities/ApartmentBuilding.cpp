#include <Models/Entities/ApartmentBuilding.h>

constexpr unsigned APARTMENT_DEFAULT_RENT = 500;

ApartmentBuilding::ApartmentBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex, const CitizenSeeder& citizenSeeder)
	: Building(denizenCapacity, yIndex, xIndex, APARTMENT_DEFAULT_RENT, citizenSeeder) { }

const std::string ApartmentBuilding::getInfoString(const std::string* name) const
{
	if (name)
		return Building::getInfoString(name);

	std::string infoString("Location " + std::to_string(yIndex) + " " + std::to_string(xIndex) + "\n");

	std::string infoString("\tType: apartment\n");

	return infoString.append(Building::getInfoString());
}

bool ApartmentBuilding::serialize(const std::string& fileName) const
{
	return false;
}

bool ApartmentBuilding::deserialize(const std::string& fileName) const
{
	return false;
}
