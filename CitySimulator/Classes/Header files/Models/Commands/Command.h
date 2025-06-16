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

	virtual std::string serializeOutput() = 0;

protected:
	Simulation& simulation;
};

