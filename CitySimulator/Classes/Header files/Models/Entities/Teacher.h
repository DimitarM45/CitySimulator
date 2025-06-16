#pragma once

#include <Models/Entities/Profession.h>

class Teacher : public Profession
{
public:
	Teacher();

	void work(unsigned& happiness) const override;

	Teacher* clone() const override;
};

