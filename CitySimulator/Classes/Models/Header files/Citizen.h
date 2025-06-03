#pragma once

#include "Building.h"

#include <string>

// The citizen class represents the actual citizens in the simulation. Their functions are handled by the abstract method live(). 
class Citizen
{
	using string = std::string;

public:
	Citizen(const string& name, Building& building, unsigned happiness, unsigned money, int lifePoints);

	virtual void live() = 0;

private:
	string name;
	Building& building;
	unsigned happiness;
	unsigned money;
	int lifePoints;

	void setHappiness(unsigned happiness);
	void setMoney(unsigned money);
	void setLifePoints(int lifePoints);
};

int getRandomInRange(int min, int max);