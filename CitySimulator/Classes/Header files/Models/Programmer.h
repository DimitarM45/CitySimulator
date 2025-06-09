#pragma once

#include "Citizen.h"

class Programmer : public Citizen
{
public:
	Programmer(const std::string& name, Building& building, unsigned happiness, double money, unsigned lifePoints);

	virtual ~Programmer() = default;

	virtual void live(unsigned dateDay) override;
private:

};

