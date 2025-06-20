#pragma once

#include <Services/Simulation.h>

namespace CommandOutputMessages
{
	const std::string SUCCESS_OUTPUT_MESSAGE = "Success!";
	const std::string FAILURE_OUTPUT_MESSAGE = "Failure!";
}

class Command
{
public:
	Command(Simulation& simulation) : simulation(simulation) {}

	virtual ~Command() = default;

	virtual bool execute() = 0;

	const std::string& getOutput() { return output; }

protected:
	Simulation& simulation;
	std::string output;
};

