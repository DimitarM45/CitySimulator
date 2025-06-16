#pragma once

#include <Models/Commands/Command.h>

class InfoCommand : public Command
{
public:
	InfoCommand(Simulation& simulation, unsigned yIndex = -1, unsigned xIndex = -1, const std::string* name = nullptr);

	bool execute() override;
	std::string serializeOutput() override;

private:
	unsigned yIndex;
	unsigned xIndex;
	const std::string* name;
};

