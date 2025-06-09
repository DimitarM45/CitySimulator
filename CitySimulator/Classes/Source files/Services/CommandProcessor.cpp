#include "../Header files/CommandProcessor.h"
#include "../../Models/Commands/Header files/StepCommand.h"

#include <stdexcept>

namespace CommandProcessorErrorMessages
{
	std::string UNKNOWN_COMMAND_ERROR_MESSAGE = "No such command exists!";
	std::string INVALID_SIMULATION_ERROR_MESSAGE = "Simulation cannot be nullptr!";
}

using namespace CommandProcessorErrorMessages;

CommandProcessor::CommandProcessor(std::ostream& outStream, std::istream& inStream, Simulation& simulation)
	: outStream(outStream), inStream(inStream), simulation(simulation)
{
	setSimulation(simulation);
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
			outStream << (execute(commandTokens) ? "Command succeeded!" : "Command failed!") << '\n';
		}
		catch (const std::exception& e)
		{
			outStream << e.what();
		}
	}
}

Simulation HistoryManager::getSimulation() const
{
	return *simulation;
}

void CommandProcessor::setSimulation(Simulation* simulation)
{
	if (!simulation)
		throw std::invalid_argument(INVALID_SIMULATION_ERROR_MESSAGE);

	this->simulation = simulation;
}

bool CommandProcessor::execute(std::vector<std::string> commandTokens)
{
	unsigned tokensSize = commandTokens.size();

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

		if (tokensSize == 2)
			steps = std::stoi(commandTokens[1]);

		command = new StepCommand(simulation, steps);
	}
	else if (commandString == "info")
	{

	}
	else if (commandString == "save")
	{

	}
	else if (commandString == "load")
	{

	}
	else
		throw std::invalid_argument(UNKNOWN_COMMAND_ERROR_MESSAGE);

	bool isSuccessful = command->execute();

	if (isSuccessful)
		outStream << command->serializeOutput();

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
