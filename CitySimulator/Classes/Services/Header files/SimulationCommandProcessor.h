#pragma once

#include "CommandProcessor.h"

class SimulationCommandProcessor : public CommandProcessor
{
public:
	SimulationCommandProcessor(std::istream& inStream, std::ostream& outStream, Simulation& simulation);
	virtual ~SimulationCommandProcessor() = default;

	void run();

protected:
	Simulation& simulation;
	bool execute(std::vector<const std::string&> commandTokens);
};

