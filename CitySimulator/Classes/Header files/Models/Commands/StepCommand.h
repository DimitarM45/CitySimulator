#pragma once

#include <Services/Simulation.h>
#include <Models/Commands/Command.h>

class StepCommand : public Command
{
public:
	StepCommand(Simulation& simulation, int steps = 1);

	bool execute() override;

private:
	int steps;
};

