#pragma once

#include <Models/Commands/Command.h>

class InfoCommand : public Command
{
public:
	InfoCommand(Simulation& simulation);
	InfoCommand(Simulation& simulation, int yIndex, int xIndex, const std::string* name = nullptr);

	bool execute() override;
	std::string serializeOutput() override;

private:
	int yIndex;
	int xIndex;
	const std::string* name;
};

