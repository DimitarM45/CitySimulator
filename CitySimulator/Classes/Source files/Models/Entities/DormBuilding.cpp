#include <Models/Entities/DormBuilding.h>

constexpr unsigned DORM_DEFAULT_RENT = 40;

DormBuilding::DormBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex, const CitizenSeeder& citizenSeeder)
	: Building(denizenCapacity, yIndex, xIndex, DORM_DEFAULT_RENT, citizenSeeder) { }

std::string DormBuilding::getInfoString(const std::string* name) const
{
	if (name)
		return Building::getInfoString(name);

	std::string infoString("Location " + std::to_string(yIndex) + " " + std::to_string(xIndex) + "\n");
	
	infoString.append("\tType: dorms");

	return infoString.append(Building::getInfoString());
}

bool DormBuilding::serialize(const std::string& fileName) const
{
	return false;
}

bool DormBuilding::deserialize(const std::string& fileName) const
{
	return false;
}
