#pragma once

#include <Models/Entities/Building.h>

class DormBuilding : public Building
{
public:
	DormBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex, const CitizenSeeder& citizenSeeder);

	const std::string getInfoString(const std::string* name) const override;

	bool serialize(const std::string& fileName) const override;

	bool deserialize(const std::string& fileName) const override;
};

