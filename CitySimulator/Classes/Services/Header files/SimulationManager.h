#pragma once

#include "Simulation.h"

class SimulationManager
{
public:
	SimulationManager(CommandProcessor& processor);

	void run();

private:
	Simulation simulation;
	CommandProcessor& processor;
};

