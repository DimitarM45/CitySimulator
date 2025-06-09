#include "../Header files/SimulationManager.h"

SimulationManager::SimulationManager(std::ostream& outStream, std::istream& inStream, const std::string& historyFileName)
	: outStream(outStream), inStream(inStream), simulation(), processor(outStream, inStream, simulation), manager(simulation, historyFileName) { }

void SimulationManager::run()
{
	processor.run();
}
