#include "../Header files/SimulationManager.h"

SimulationManager::SimulationManager(CommandProcessor& processor, HistoryManager<Matrix<Building>>& manager)
	: processor(processor), manager(manager)
{
	
}

void SimulationManager::run()
{
	processor.run();
}
