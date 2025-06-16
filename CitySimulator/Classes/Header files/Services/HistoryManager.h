#pragma once

#include "Simulation.h"

#include <vector>

class HistoryManager
{
public:
	HistoryManager(Simulation& simulation, const std::string& historyFileName);

	bool writeHistory();

	Simulation& getSimulation() const;

private:
	unsigned cacheIndex;
	unsigned maxCacheSize;
	std::string historyFileName;

	Simulation& simulation;
	std::vector<Simulation> cache;

	bool readHistory();
};

