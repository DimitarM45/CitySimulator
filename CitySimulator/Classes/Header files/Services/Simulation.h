#pragma once

#include <string>
#include <Utilities/Date.h>
#include <Models/Entities/City.h>
#include <Models/Entities/Citizen.h>

enum class SeedOption
{
	ReadFromFile = 0,
	RandomSeed = 1
};

class Simulation
{
public:
	Simulation();
	Simulation(SeedOption seedOption);

	void executeSteps(int steps = 1);
	void configure(SeedOption seedOption);
	void reset();

	City& getCity();
	bool addDenizen(unsigned yIndex, unsigned xIndex, Citizen& denizen);
	bool removeDenizen(unsigned yIndex, unsigned xIndex, const std::string& name);

	void saveState(std::ostream& outStream);

	unsigned getDeadPeopleCount() const;

	Date getDate() const;

private:
	City city;
	Date date;
	bool isReset;
	bool isConfigured;
	unsigned currentDeadPeople;

	void loadState(std::istream& inStream);
	void seed();
};