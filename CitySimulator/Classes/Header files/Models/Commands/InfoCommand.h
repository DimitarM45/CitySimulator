#pragma once

#include <Models/Commands/Command.h>

class InfoCommand : public Command
{
public:
	InfoCommand(Simulation& simulation);
	InfoCommand(Simulation& simulation, int yIndex, int xIndex, const std::string* citizenName = nullptr);

	bool execute() override;

private:
	int yIndex;
	int xIndex;
	const std::string* citizenName;
};

