#pragma once

#include <vector>
#include <Models/Entities/Citizen.h>
#include <Models/Entities/ISerializable.h>

class Building : public ISerializable
{
public:
	Building(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex, unsigned rent);
	virtual ~Building() = default;
	
	virtual void passDay(unsigned dateDay) = 0;

	unsigned getRent() const;
	bool getIsCentral() const;
	Citizen* getDenizen(const std::string& name);

	bool addDenizen(Citizen& denizen);
	bool removeDenizen(const std::string& name);

	virtual std::string getInfoString(const std::string* name = nullptr) const = 0;

	virtual bool serialize(const std::string& fileName) const = 0;
	virtual bool deserialize(const std::string& fileName) const = 0;

protected:
	std::vector<Citizen*> denizens;
	unsigned rent;
	unsigned yIndex;
	unsigned xIndex;
	unsigned denizenCapacity;
	bool isCentral;

	void setRent(unsigned rent);
	bool isCentralBuilding(unsigned yIndex, unsigned xIndex);
};

