#pragma once

#include "Building.h"
#include "ISerializable.h"

#include <string>

enum class Profession
{
	Teacher = 0,
	Miner = 1,
	Programmer = 2,
	Unemployed = 3
};

// The citizen class represents the actual citizens in the simulation. Their functions are handled by the abstract method live(). 
class Citizen : public ISerializable
{
public:
	Citizen(const std::string& name, Building& building, unsigned happiness, unsigned money, unsigned lifePoints);

	virtual void live(unsigned dateDay) = 0;

	const std::string& getName() const;
	unsigned getHappiness() const;
	unsigned getMoney() const;
	unsigned getLifePoints() const;	

	virtual std::string getInfoString() const = 0;

	virtual bool serialize(const std::string& fileName) const = 0;
	virtual bool deserialize(const std::string& fileName) const = 0;

protected:
	std::string name;
	Building& building;
	unsigned happiness;
	unsigned money;
	unsigned lifePoints;

	struct State
	{
		unsigned happiness;
		unsigned money;
		unsigned lifePoints;
	};

	std::vector<State> states;

	void setName(const std::string& name);
	void setHappiness(unsigned happiness);
	void setMoney(unsigned money);
	void setLifePoints(unsigned lifePoints);
};
