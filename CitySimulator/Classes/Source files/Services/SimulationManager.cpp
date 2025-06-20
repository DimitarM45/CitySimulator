#include <string>
#include <iostream>
#include <Services/SimulationManager.h>

SimulationManager::SimulationManager(std::ostream& outStream, std::istream& inStream)
	: outStream(outStream), inStream(inStream), simulation(), processor(outStream, inStream, simulation) { }

void SimulationManager::run()
{
	processor.run();
}
