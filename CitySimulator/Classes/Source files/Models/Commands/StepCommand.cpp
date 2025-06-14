#include "../Header files/StepCommand.h"

StepCommand::StepCommand(Simulation& simulation, int steps)
	: simulation(simulation), steps(steps) { }

bool StepCommand::execute()
{
	simulation.executeSteps(steps);

	return true;
}

std::string StepCommand::serializeOutput()
{
	return std::to_string(simulation.getDeadPeopleCount());
}
