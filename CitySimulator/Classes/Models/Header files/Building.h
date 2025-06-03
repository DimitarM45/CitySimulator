#pragma once

#include "Citizen.h"
#include "../../Utilities/Header files/Matrix.h"

#include <vector>

class Building
{
	using vector = std::vector<Citizen>;

public:
	Building(unsigned denizenCount, unsigned xIndex, unsigned yIndex, unsigned rent);
	
	void passDay();

	unsigned getRent() const;
	bool getIsCentral() const;

private:
	vector denizens;
	unsigned rent;
	unsigned denizenCount;
	unsigned xIndex;
	unsigned yIndex;
	bool isCentral;

	void setRent(unsigned rent);
	bool isCentralBuilding(unsigned xIndex, unsigned yIndex);
};

short min(unsigned xIndex, unsigned yIndex);

