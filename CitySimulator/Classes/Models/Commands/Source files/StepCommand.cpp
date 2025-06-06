#include "../Header files/StepCommand.h"

StepCommand::StepCommand(std::ostream& outStream, Simulation& simulation, int steps)
	: Command(outStream), simulation(simulation), steps(steps) { }

bool StepCommand::execute()
{
	simulation.executeSteps(steps);

	serializeOutput();

	return true;
}

void StepCommand::serializeOutput()
{
	outStream << simulation.getDeadPeopleCount() << std::endl;
}
