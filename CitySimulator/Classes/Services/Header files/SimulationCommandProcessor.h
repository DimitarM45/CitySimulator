#pragma once

#include "CommandProcessor.h"

class SimulationCommandProcessor : public CommandProcessor
{
public:
	SimulationCommandProcessor(std::istream& inStream, std::ostream& outStream);

	virtual ~SimulationCommandProcessor() = default;

	virtual bool execute(std::vector<const std::string&> commandTokens) override;

private:
};

