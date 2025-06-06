#include "../Header files/SimulationCommandProcessor.h"
#include "../../Models/Commands/Header files/StepCommand.h"

SimulationCommandProcessor::SimulationCommandProcessor(std::istream& inStream, std::ostream& outStream, Simulation& simulation)
    : CommandProcessor(inStream, outStream), simulation(simulation) { }

bool SimulationCommandProcessor::execute(std::vector<const std::string&> commandTokens)
{
	std::string commandString = commandTokens[0];

	Command* command;

	if (commandString == "generate")
	{

	}	
	else if (commandString == "add")
	{

	}
	else if (commandString == "remove")
	{

	}
	else if (commandString == "step")
	{
		unsigned steps = 1;

		if (commandTokens.size() == 2)
			steps = std::stoi(commandTokens[1]);

		command = &StepCommand(outStream, simulation, steps);
	}

	return command->execute();
}
