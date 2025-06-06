#pragma once

#include <vector>
#include <string>

class CommandProcessor
{
public:
	CommandProcessor(std::istream& inStream, std::ostream& outStream);

	virtual void run() = 0;

	virtual ~CommandProcessor() = default;

protected:
	virtual bool execute(std::vector<std::string> commandTokens) = 0;
	std::vector<std::string> parseCommand(std::string command);

	std::istream& inStream;
	std::ostream& outStream;
};

void trimString(std::string& string);
