#pragma once

#include "Simulation.h"
#include "HistoryManager.h"
#include "CommandProcessor.h"

class SimulationManager
{
public:
	SimulationManager(std::ostream& outStream, std::istream& inStream, const std::string& historyFileName);

	void run();

private:
	Simulation simulation;
	CommandProcessor processor;
	HistoryManager manager;

	std::ostream& outStream;
	std::istream& inStream;
};

