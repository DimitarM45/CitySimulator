#pragma once

#include "Building.h"

#include <string>

// The citizen class represents the actual citizens in the simulation. Their functions are handled by the abstract method live(). 
class Citizen
{
public:
	Citizen(const std::string& name, Building& building, unsigned happiness, double money, unsigned lifePoints);

	virtual void live(unsigned day) = 0;

	const std::string& getName() const;
	unsigned getHappiness() const;
	double getMoney() const;
	unsigned getLifePoints() const;	

	virtual std::ostream& operator<<(std::ostream& out);
private:
	std::string name;
	Building& building;
	unsigned happiness;
	double money;
	unsigned lifePoints;

	void setName(const std::string& name);
	void setHappiness(unsigned happiness);
	void setMoney(double money);
	void setLifePoints(int lifePoints);
};
