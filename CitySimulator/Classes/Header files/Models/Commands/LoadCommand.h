#pragma once

#include <Models/Commands/Command.h>

class LoadCommand : public Command
{
public:
	LoadCommand(Simulation& simulation, const std::string& fileName);

	bool execute() override;

private:
	const std::string& fileName;
};

