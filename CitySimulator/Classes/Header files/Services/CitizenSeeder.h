#pragma once

#include <Models/Entities/Citizen.h>

class CitizenSeeder
{
public:
	CitizenSeeder(const std::string& fileName = "citizen_names.txt", Building* building = nullptr);

	Citizen* getRandom() const;

	void setBuilding(Building& building);

private:
	const std::string& fileName;
	Building* building;
};

