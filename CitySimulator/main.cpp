#include "Classes/Services/Header files/SimulationManager.h"
#include "Classes/Services/Header files/SimulationCommandProcessor.h"

#include <iostream>

int main()
{
	CommandProcessor commandProcessor = new SimulationCommandProcessor();
	HistoryManager historyManager = HistoryManager();
	SimulationManager simManager(commandProcessor);

	simManager.run();
}