#pragma once

#include <Models/Commands/Command.h>

class RemoveCommand : public Command
{
public:
	RemoveCommand(Simulation& simulation, unsigned yIndex, unsigned xIndex, const std::string& name);

	bool execute() override;

private:
	unsigned yIndex;
	unsigned xIndex;
	const std::string& name;
};

