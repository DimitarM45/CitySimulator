#pragma once

#include "Citizen.h"

#include <vector>

using std::vector;

class Building
{
public:
	Building(bool isCentral, unsigned denizenCapacity);

	bool getIsCentral() const;
	
	void simulateDay();

private:
	vector<Citizen> denizens;
	bool isCentral;
	unsigned denizenCapacity;
	unsigned denizenCount;
};

