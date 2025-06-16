#pragma once

#include <Models/Entities/Citizen.h>

class Programmer : public Citizen
{
public:
	Programmer(const std::string& name, Building& building, unsigned happiness, double money, unsigned lifePoints);

	virtual void live(unsigned dateDay) override;

	// Inherited via Citizen
	bool serialize(const std::string& fileName) const override;
	bool deserialize(const std::string& fileName) const override;
};

