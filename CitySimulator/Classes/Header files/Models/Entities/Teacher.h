#pragma once

#include <Models/Entities/Citizen.h>

class Teacher : public Citizen
{
public:
	Teacher(const std::string& name, Building& building, unsigned happiness, unsigned money, unsigned lifePoints);

	void live(unsigned dateDay) override;

	bool serialize(const std::string& fileName) const override;
	bool deserialize(const std::string& fileName) const override;
};

