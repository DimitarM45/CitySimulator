#include <Models/Commands/SaveCommand.h>

SaveCommand::SaveCommand(Simulation& simulation, const std::string& fileName)
	: Command(simulation), fileName(fileName) { }

bool SaveCommand::execute()
{
	using namespace CommandOutputMessages;

	bool isSuccessful = simulation.serialize(fileName);

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
