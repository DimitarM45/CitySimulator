#pragma once

#include <Models/Commands/Command.h>

class SaveCommand : public Command
{
public:
	SaveCommand(Simulation& simulation, const std::string& fileName);

	bool execute() override;

private:
	const std::string& fileName;
};

