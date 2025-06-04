#pragma once

#include <vector>
#include <string>

class CommandProcessor
{
public:
	CommandProcessor(std::istream& inStream, std::ostream& outStream);

	virtual void run() = 0;

	virtual ~CommandProcessor() = default;

private:
	std::istream& inStream;
	std::ostream& outStream;

	virtual bool execute(std::vector<std::string> commandTokens) = 0;
	std::vector<std::string> parseCommand(std::string command);
};

void trimString(std::string& string);
