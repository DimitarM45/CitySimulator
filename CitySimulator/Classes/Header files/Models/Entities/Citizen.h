#pragma once

#include "Building.h"
#include "ISerializable.h"
#include <Models/Entities/Profession.h>

#include <string>

enum class ProfessionType
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
	Citizen(const std::string& name, Building& building, ProfessionType professionType, unsigned happiness, unsigned money, unsigned lifePoints);
	Citizen(const Citizen& other);
	Citizen& operator=(const Citizen& other);
	~Citizen();

	void live(unsigned dateDay);

	const std::string& getName() const;
	unsigned getHappiness() const;
	unsigned getMoney() const;
	unsigned getLifePoints() const;	

	std::string getInfoString() const;

	bool serialize(const std::string& fileName) const;
	bool deserialize(const std::string& fileName) const;

protected:
	std::string name;
	Building& building;
	Profession* profession;
	struct Status
	{
		unsigned happiness;
		unsigned money;
		unsigned lifePoints;
	} status;

	std::vector<Status> statuses;

	void setName(const std::string& name);
	void setHappiness(unsigned happiness);
	void setMoney(unsigned money);
	void setLifePoints(unsigned lifePoints);
	void setProfession(ProfessionType professionType);

	void free();
	void copyFrom(const Citizen& other);
};
