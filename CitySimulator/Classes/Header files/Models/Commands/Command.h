#pragma once

class Command
{
public:
	Command(Simulation& simulation) : simulation(simulation) {}

	virtual ~Command() = default;

	virtual bool execute() = 0;

	virtual std::string serializeOutput() = 0;

private:
	Simulation& simulation;
};

