#pragma once

#include <Models/Entities/Profession.h>

class Unemployed : public Profession
{
public:
	Unemployed(Citizen& citizen);

	void work() const override;

	Unemployed* clone(Citizen& citizen) const override;

	const std::string getInfoString() const override;
};

