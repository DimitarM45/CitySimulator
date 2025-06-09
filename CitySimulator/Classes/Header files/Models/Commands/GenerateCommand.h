#pragma once

#include "Command.h"
#include <Models/simulation.h>

#include <ostream>

class GenerateCommand : public Command
{
public:
	GenerateCommand(Simulation& simulation);

	bool execute() override;
private:
	Simulation& simulation;

	std::string serializeOutput() override;
};

