#include "Classes/Services/Header files/SimulationManager.h"
#include "Classes/Services/Header files/SimulationCommandProcessor.h"

#include <iostream>

int main()
{
	CommandProcessor commandProcessor = new SimulationCommandProcessor();
	SimulationManager simManager(commandProcessor);

	simManager.run();
}