#pragma once

#include "Building.h"

#include <string>

class Profession;

enum class ProfessionType
{
	Teacher = 0,
	Miner = 1,
	Programmer = 2,
	Unemployed = 3
};

// The citizen class represents the actual citizens in the simulation. Their functions are handled by the abstract method live(). 
class Citizen
{
public:
	Citizen(const std::string& name, Building& building, ProfessionType professionType, int happiness, int money, int lifePoints);
	Citizen(const Citizen& other);
	Citizen& operator=(const Citizen& other);
	~Citizen();

	void live(unsigned dateDay);

	const std::string& getName() const;
	int getHappiness() const;
	int getMoney() const;
	int getLifePoints() const;	

	void setMoney(int money);
	void setHappiness(int happiness);
	void setLifePoints(int lifePoints);

	const std::string getInfoString() const;

	bool serialize(const std::string& fileName) const;
	bool deserialize(const std::string& fileName) const;

protected:
	std::string name;
	Building& building;
	Profession* profession;
	struct Status
	{
		int happiness;
		int money;
		int lifePoints;
	} status;

	std::vector<Status> statuses;

	void setName(const std::string& name);
	void setProfession(ProfessionType professionType);

	void seed();

	void free();
	void copyFrom(const Citizen& other);
};
