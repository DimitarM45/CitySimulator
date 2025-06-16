#pragma once

#include <Models/Entities/Citizen.h>

class Miner : public Citizen
{
public:
	Miner(const std::string& name, Building& building, unsigned happiness, unsigned money, unsigned lifePoints);

	// Inherited via Citizen
	void live(unsigned dateDay) override;

	// Inherited via Citizen
	bool serialize(const std::string& fileName) const override;
	bool deserialize(const std::string& fileName) const override;
};

