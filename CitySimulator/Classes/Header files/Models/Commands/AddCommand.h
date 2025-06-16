#pragma once

#include "Command.h"

class AddCommand : public Command
{
public:
	AddCommand(Simulation& simulation, unsigned yIndex, unsigned xIndex, const std::string& citizenName,
		Profession job, unsigned happiness, unsigned money, unsigned lifePoints);

	bool execute() override;

	std::string serializeOutput() override;

private:
	unsigned yIndex;
	unsigned xIndex;
	const std::string& citizenName;
	Profession profession;
	unsigned happiness;
	unsigned money;
	unsigned lifePoints;
	bool isSuccessful;
};

