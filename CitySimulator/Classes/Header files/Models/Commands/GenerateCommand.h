#pragma once

#include <Services/Simulation.h>
#include <Models/Commands/Command.h>

class GenerateCommand : public Command
{
public:
	GenerateCommand(Simulation& simulation, unsigned length, unsigned width);

	bool execute() override;

private:
	unsigned length;
	unsigned width;
};

