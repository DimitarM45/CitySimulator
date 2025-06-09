#pragma once

#include <vector>
#include <string>

class CommandProcessor
{
public:
	CommandProcessor(std::ostream& outStream, std::istream& inStream, Simulation& simulation);

	void run();

private:
	std::ostream& outStream;
	std::istream& inStream;
	Simulation& simulation;

	bool execute(std::vector<std::string> commandTokens);
	std::vector<std::string> parseCommand(std::string command);
};

void trimString(std::string& string);
