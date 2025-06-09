#pragma once

#include <Services/Simulation.h>
#include <Models/Commands/Command.h>

class GenerateCommand : public Command
{
public:
	GenerateCommand(Simulation& simulation);

	bool execute() override;
private:
	Simulation& simulation;

	std::string serializeOutput() override;
};

