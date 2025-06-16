#pragma once

#include <Models/Commands/Command.h>

class RemoveCommand : public Command
{
public:
	RemoveCommand(Simulation& simulation, unsigned yIndex, unsigned xIndex, const std::string& name);

	bool execute() override;
	std::string serializeOutput() override;

private:
	bool isSuccessful;
	unsigned yIndex;
	unsigned xIndex;
	const std::string& name;
};

