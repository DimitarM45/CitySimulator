#pragma once

#include <vector>
#include <Models/Entities/Citizen.h>
#include <Services/CitizenSeeder.h>

namespace BuildingConstants
{
	const unsigned CENTRAL_RENT_MULTIPLIER = 2.5;
	const unsigned SUBURBAN_RENT_MULTIPLIER = 0.2;
	const unsigned MAX_CITIZEN_CAPACITY = 400;
}

enum class BuildingType
{
	DormBuilding = 0,
	ApartmentBuilding = 1,
	ModernBuilding = 2
};

class Building
{
public:
	Building(unsigned citizenCapacity, unsigned yIndex, unsigned xIndex, unsigned rent, const CitizenSeeder& citizenSeeder);
	Building(const Building& other);
	Building& operator=(const Building& other);
	virtual ~Building() = default;
	
	void passDay(unsigned dateDay);

	unsigned getRent() const;
	bool getIsCentral() const;
	Citizen* getCitizen(const std::string& name);
	
	std::vector<Citizen>& getCitizens();

	bool addCitizen(Citizen& citizen);
	bool removeCitizen(const std::string& name);

	void seedCitizens();

	virtual const std::string getInfoString(const std::string* citizenName = nullptr) const;

	virtual bool serialize(const std::string& fileName) const = 0;
	virtual bool deserialize(const std::string& fileName) const = 0;

protected:
	std::vector<Citizen> citizens;
	unsigned rent;
	unsigned yIndex;
	unsigned xIndex;
	unsigned citizenCapacity;
	bool isCentral;
	const CitizenSeeder& citizenSeeder;

	void setCitizenCapacity(unsigned citizenCapacity);
	void setRent(unsigned rent);
	bool isCentralBuilding(unsigned yIndex, unsigned xIndex);

	void copyFrom(const Building& other);
};

