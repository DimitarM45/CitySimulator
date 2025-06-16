#pragma once

#include <Models/Entities/Profession.h>

class Programmer : public Profession
{
public:
	Programmer();

	void work(unsigned& happiness) const override;

	Programmer* clone() const override;
};

