#include "../Header files/SimulationCommandProcessor.h"

SimulationCommandProcessor::SimulationCommandProcessor(std::istream& inStream, std::ostream& outStream)
    : CommandProcessor(inStream, outStream) { }

bool SimulationCommandProcessor::execute(std::vector<const std::string&> commandTokens)
{
    return false;
}
