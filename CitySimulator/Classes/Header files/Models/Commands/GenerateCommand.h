#pragma once

#include <Services/Simulation.h>
#include <Models/Commands/Command.h>

class GenerateCommand : public Command
{
public:
	GenerateCommand(Simulation& simulation, SeedOption seedOption);

	bool execute() override;

	std::string serializeOutput() override;

private:
	SeedOption seedOption;
};

