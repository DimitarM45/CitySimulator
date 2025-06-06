#pragma once

#include "Simulation.h"
#include "HistoryManager.h"

class SimulationManager
{
public:
	SimulationManager(CommandProcessor& processor, HistoryManager<Matrix<Building>>& manager);

	void run();

private:
	Simulation simulation;
	CommandProcessor& processor;
	HistoryManager<Matrix<Building>>& manager;
};

