#pragma once

#include <ostream>

class Command
{
public:
	Command(std::ostream& outStream);

	virtual ~Command() = default;

	virtual bool execute() = 0;

protected:
	std::ostream& outStream;

	virtual void serializeOutput() = 0;
};

