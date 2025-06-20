#pragma once

#include "Simulation.h"
#include "CommandProcessor.h"

class SimulationManager
{
public:
	SimulationManager(std::ostream& outStream, std::istream& inStream);

	void run();

private:
	Simulation simulation;
	CommandProcessor processor;

	std::ostream& outStream;
	std::istream& inStream;
};

