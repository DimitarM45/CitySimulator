#include <Services/Simulation.h>
#include <Models/Commands/StepCommand.h>

StepCommand::StepCommand(Simulation& simulation, int steps)
	: Command(simulation), steps(steps) { }

bool StepCommand::execute()
{
	simulation.executeSteps(steps);

	return true;
}

std::string StepCommand::serializeOutput()
{
	return std::to_string(simulation.getDeadPeopleCount());
}
