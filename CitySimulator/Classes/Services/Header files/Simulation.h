#pragma once

#include "HistoryManager.h"
#include "CommandProcessor.h"
#include "../../Models/Header files/City.h"
#include "../../Utilities/Header files/Date.h"

#include <string>

enum class SeedOption
{
	ReadFromFile = 0,
	RandomSeed = 1
};

class Simulation
{
public:
	Simulation();

	void executeSteps(int steps = 1);
	void reset();
	void addDenizen(const Citizen& denizen);

	void saveState(std::ostream& outStream);
	void configure(SeedOption seedOption);

	unsigned getDeadPeopleCount() const;
private:
	City city;
	Date date;
	bool isReset;
	bool isCreatedSuccessfully;
	unsigned currentDeadPeople;

	void load(SeedOption option);
	void loadState(std::istream& inStream);
	void seed();
};