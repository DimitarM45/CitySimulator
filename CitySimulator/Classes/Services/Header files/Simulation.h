#pragma once

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
	void executeSteps(int steps = 1);
	void pause();
	void stop();
	void reset();

	void saveState(std::ostream& outStream);
	void load(SeedOption option);

private:
	City* city;
	unsigned speed;
	Date date;
	bool isReset;

	void loadState(std::istream& inStream);
	void seed();
};

