#pragma once

#include <Models/Entities/Profession.h>

class Teacher : public Profession
{
public:
	Teacher(Citizen& citizen);

	void work() const override;

	Teacher* clone(Citizen& citizen) const override;

	const std::string getInfoString() const override;
};

