#pragma once

#include <string>
#include <Utilities/Date.h>
#include <Utilities/Matrix.h.>
#include <Models/Entities/Citizen.h>
#include "BuildingSeeder.h"

class Simulation
{
public:
	Simulation();
	Simulation(const Simulation& other);
	Simulation& operator=(const Simulation& other);
	~Simulation();

	void seed(unsigned length, unsigned width);

	void executeSteps(int steps = 1);

	Matrix<Building*>& getBuildings();
	bool addCitizen(unsigned yIndex, unsigned xIndex, Citizen& denizen);
	bool removeCitizen(unsigned yIndex, unsigned xIndex, const std::string& name);

	const std::string getAllInfo() const;
	const std::string getBuildingInfo(unsigned yIndex, unsigned xIndex);
	const std::string getCitizenInfo(unsigned yIndex, unsigned xIndex, const std::string& citizenName);

	bool serialize(const std::string& fileName) const;
	bool deserialize(const std::string& fileName);

	bool getWasSeeded() const;
	bool getWasLoaded() const;

	unsigned getDeadPeopleCount();

	Date getDate() const;

private:
	Date date;
	unsigned currentDeadPeople;
	unsigned daysSinceStart;
	std::vector<Simulation> states;
	bool wasSeeded;
	bool wasLoaded;
	mutable Matrix<Building*> buildings;
	BuildingSeeder buildingSeeder;

	Building* getBuilding(unsigned yIndex, unsigned xIndex);
	void copyFrom(const Simulation& other);
	void free();
};