#pragma once

#include "Command.h"
#include "../../../Services/Header files/Simulation.h"

class StepCommand : public Command
{
public:
	StepCommand(Simulation& simulation, int steps = 1);

	bool execute() override;

	std::string serializeOutput() override;

private:
	Simulation& simulation;
	int steps;
};

