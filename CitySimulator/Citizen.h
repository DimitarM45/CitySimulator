#pragma once

#include <string>

#include "Building.h"
#include "Profession.h"

using std::string;

class Citizen
{
public:
	Citizen(const string name, const Profession& profession, const Building& building, unsigned happiness, unsigned money, int lifePoints);
	Citizen(const Citizen& other);
	Citizen& operator=(const Citizen& other);
	~Citizen();

	void live();

private:
	string name;
	Profession* profession;
	Building* building;
	unsigned happiness;
	unsigned money;
	int lifePoints;

	void setName(string name);
	void setHappiness(unsigned happiness);
	void setMoney(unsigned money);
	void setLifePoints(int lifePoints);

	void free();
	void copyFrom(const Citizen& other);
};

