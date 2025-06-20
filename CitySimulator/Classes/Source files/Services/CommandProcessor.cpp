#include <iostream>
#include <stdexcept>

#include <Services/CommandProcessor.h>

#include <Services/Simulation.h>

#include <Models/Commands/AddCommand.h>
#include <Models/Commands/StepCommand.h>
#include <Models/Commands/InfoCommand.h>
#include <Models/Commands/SaveCommand.h>
#include <Models/Commands/LoadCommand.h>
#include <Models/Commands/RemoveCommand.h>
#include <Models/Commands/GenerateCommand.h>

namespace CommandProcessorErrorMessages
{
	const std::string UNKNOWN_COMMAND_ERROR_MESSAGE = "No such command exists!";
	const std::string SIMULATION_NOT_CONFIGURED_ERROR_MESSAGE = "Simulation is not configured! Use generate or load first!";
}

using namespace CommandProcessorErrorMessages;

CommandProcessor::CommandProcessor(std::ostream& outStream, std::istream& inStream, Simulation& simulation)
	: outStream(outStream), inStream(inStream), simulation(simulation), currentSaveFileName("")
{

}

void CommandProcessor::run()
{
	constexpr unsigned bufferSize = 1024;

	char buffer[bufferSize];
	std::string stringBuffer;

	while (inStream.getline(buffer, bufferSize))
	{
		std::vector<std::string> commandTokens = parseCommand(buffer);

		if (commandTokens[0] == "end")
		{
			outStream << "Exiting program...";

			return;
		}

		try
		{
			execute(commandTokens);
		}
		catch (const std::exception& e)
		{
			outStream << e.what() << std::endl;
		}
	}
}

bool CommandProcessor::execute(std::vector<std::string> commandTokens)
{
	unsigned tokensSize = commandTokens.size();

	std::string commandString = commandTokens[0];

	Command* command;

	if (commandString == "generate")
	{
		if (simulation.getWasLoaded() || simulation.getWasSeeded())
			simulation.serialize(currentSaveFileName);

		command = new GenerateCommand(simulation);
	}
	else if (commandString == "load")
	{
		if (simulation.getWasLoaded() || simulation.getWasSeeded())
			simulation.serialize(currentSaveFileName);

		command = new LoadCommand(simulation, commandTokens[1]);

		currentSaveFileName = commandTokens[1];
	}
	else if (simulation.getWasSeeded() || simulation.getWasLoaded())
	{
		if (commandString == "add")
		{
			int yIndex = std::stoi(commandTokens[1]);
			int xIndex = std::stoi(commandTokens[2]);
			std::string citizenName = commandTokens[3];
			ProfessionType professionType = (ProfessionType)std::stoi(commandTokens[4]);
			int happiness = std::stoi(commandTokens[5]);
			int money = std::stoi(commandTokens[6]);
			int life = std::stoi(commandTokens[7]);

			command = new AddCommand(simulation, yIndex, xIndex, citizenName, professionType, happiness, money, life);
		}
		else if (commandString == "remove")
		{
			int yIndex = std::stoi(commandTokens[1]);
			int xIndex = std::stoi(commandTokens[2]);

			command = new RemoveCommand(simulation, yIndex, xIndex, commandTokens[3]);
		}
		else if (commandString == "step")
		{
			unsigned steps = 1;

			if (tokensSize == 2)
				steps = std::stoi(commandTokens[1]);

			command = new StepCommand(simulation, steps);
		}
		else if (commandString == "info")
		{
			if (tokensSize == 1)
			{
				command = new InfoCommand(simulation);
			}
			else if (tokensSize == 3)
			{
				command = new InfoCommand(simulation, std::stoi(commandTokens[1]), std::stoi(commandTokens[2]));
			}
			else if (tokensSize == 4)
			{
				command = new InfoCommand(simulation, std::stoi(commandTokens[1]), std::stoi(commandTokens[2]), &commandTokens[3]);
			}
		}
		else if (commandString == "save")
		{
			command = new SaveCommand(simulation, commandTokens[1]);
		}
		else
			throw std::invalid_argument(UNKNOWN_COMMAND_ERROR_MESSAGE);
	}
	else
	{
		throw std::logic_error(SIMULATION_NOT_CONFIGURED_ERROR_MESSAGE);
	}

	bool isSuccessful = command->execute();

	outStream << command->getOutput();

	delete command;

	return isSuccessful;
}

std::vector<std::string> CommandProcessor::parseCommand(std::string command)
{
	trimString(command);

	unsigned commandLength = command.length();

	unsigned spaceCount = 0;

	for (size_t i = 0; i < commandLength; i++)
	{
		if (command[i] == ' ')
			spaceCount++;
	}

	int* spaceIndices = new int[spaceCount];

	for (size_t i = 0; i < spaceCount; i++)
	{
		if (command[i] == ' ')
			spaceIndices[i] = i;
	}

	unsigned commandTokensCount = spaceCount + 1;

	std::vector<std::string> commandTokens(commandTokensCount);

	for (size_t i = 0; i < commandTokensCount; i++)
	{
		std::string currCommand;

		for (size_t j = spaceIndices[i] + 1; command[j] != ' '; j++)
			currCommand.append(std::to_string(command[j]));

		commandTokens[i] = currCommand;
	}

	return commandTokens;
}

void trimString(std::string& string)
{
	if (string.empty())
		return;

	unsigned stringLength = string.length();

	unsigned leftSpaceCount = 0;

	for (size_t i = 0; string[i] == ' '; i++)
		leftSpaceCount++;

	unsigned rightSpaceCount = 0;

	for (size_t i = stringLength - 1; string[i] == ' '; i--)
		rightSpaceCount++;

	string.erase(0, leftSpaceCount);
	string.erase(stringLength - 1, rightSpaceCount);
}
