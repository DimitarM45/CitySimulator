#pragma once

#include "City.h"

#include <string>

enum class SeedOption
{
	ReadFromFile = 0,
	RandomSeed = 1
};

class Simulation
{
public:
	Simulation(unsigned speed);

	void run(SeedOption seedOption);
	void pause();
	void stop();

	void saveState(std::ostream& outStream);
	void loadState(std::istream& inStream);

	void setSpeed(unsigned speed);

private:
	City* city;
	tm dateTime;
	unsigned speed;

	void seed(SeedOption seedOption);
};

