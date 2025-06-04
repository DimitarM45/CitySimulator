#include "../Header files/CommandProcessor.h"

CommandProcessor::CommandProcessor(std::istream& inStream, std::ostream& outStream)
	: inStream(inStream), outStream(outStream) { }

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
