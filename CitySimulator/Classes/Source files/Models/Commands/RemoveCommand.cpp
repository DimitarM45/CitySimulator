#include <Models/Commands/RemoveCommand.h>

RemoveCommand::RemoveCommand(Simulation& simulation, unsigned yIndex, unsigned xIndex, const std::string& name)
    : Command(simulation), yIndex(yIndex), xIndex(xIndex), name(name) { }

bool RemoveCommand::execute()
{
	using namespace CommandOutputMessages;

	bool isSuccessful = simulation.removeCitizen(yIndex, xIndex, name);

	if (isSuccessful)
	{
		output = SUCCESS_OUTPUT_MESSAGE;
	}
	else
	{
		output = FAILURE_OUTPUT_MESSAGE;
	}

	return isSuccessful;
}
