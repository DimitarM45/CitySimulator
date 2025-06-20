#pragma once

#include <Models/Entities/Building.h>

class BuildingSeeder
{
public:
	BuildingSeeder(const CitizenSeeder* citizenSeeder = nullptr);

	Building* getRandom(unsigned yIndex, unsigned xIndex) const;

	void setCitizenSeeder(const CitizenSeeder& citizenSeeder);

private:
	const CitizenSeeder* citizenSeeder;
};

