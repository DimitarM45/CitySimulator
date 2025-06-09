#include "../Header files/HistoryManager.h"

HistoryManager::HistoryManager(Simulation& simulation, const std::string& historyFileName)
	: simulation(simulation) 
{ 
	this->historyFileName = historyFileName;
}

bool HistoryManager::writeHistory()
{
	return false;
}

bool HistoryManager::readHistory()
{
	return false;
}
