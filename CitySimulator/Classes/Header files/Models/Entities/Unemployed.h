#pragma once

#include <Models/Entities/Profession.h>

class Unemployed : public Profession
{
public:
	Unemployed();

	void work(unsigned& life) const override;

	Unemployed* clone() const override;
};

