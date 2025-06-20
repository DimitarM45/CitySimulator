#pragma once

#include <Models/Entities/Building.h>

class ModernBuilding : public Building
{
public:
	ModernBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex, const CitizenSeeder& citizenSeeder);

	// Inherited via Building
	const std::string getInfoString(const std::string* name) const override;
	bool serialize(const std::string& fileName) const override;
	bool deserialize(const std::string& fileName) const override;
};

