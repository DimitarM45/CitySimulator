#pragma once

#include <Models/Commands/Command.h>
#include <Models/Entities/Profession.h>

class AddCommand : public Command
{
public:
	AddCommand(Simulation& simulation, int yIndex, int xIndex, const std::string& citizenName,
		ProfessionType professionType, int happiness, int money, int lifePoints);

	bool execute() override;

private:
	int yIndex;
	int xIndex;
	const std::string& citizenName;
	ProfessionType professionType;
	int happiness;
	int money;
	int lifePoints;
};

