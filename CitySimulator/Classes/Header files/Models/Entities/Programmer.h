#pragma once

#include <Models/Entities/Profession.h>

class Programmer : public Profession
{
public:
	Programmer(Citizen& citizen);

	void work() const override;

	Programmer* clone(Citizen& citizen) const override;

	const std::string getInfoString() const override;
};

