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
	Simulation(HistoryManager& historyManager);

	void executeSteps(int steps = 1);
	void stop();
	void reset();

	void saveState(std::ostream& outStream);

private:
	City city;
	HistoryManager& historyManager;
	Date date;
	bool isReset;

	void load(SeedOption option);
	void loadState(std::istream& inStream);
	void seed();
};