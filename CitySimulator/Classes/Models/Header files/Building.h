#pragma once

#include "Citizen.h"
#include "../../Utilities/Header files/Matrix.h"

#include <vector>

class Building
{
public:
	Building(unsigned denizenCount, unsigned yIndex, unsigned xIndex, unsigned rent);
	
	virtual void passDay(unsigned dateDay) = 0;

	unsigned getRent() const;
	bool getIsCentral() const;

private:
	std::vector<Citizen*> denizens;
	unsigned rent;
	unsigned yIndex;
	unsigned xIndex;
	bool isCentral;

	void setRent(unsigned rent);
	bool isCentralBuilding(unsigned yIndex, unsigned xIndex);
};

short min(unsigned yIndex, unsigned xIndex);

