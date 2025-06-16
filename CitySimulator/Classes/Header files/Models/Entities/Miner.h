#pragma once

#include <Models/Entities/Profession.h>

class Miner : public Profession
{
public:
	Miner();

	void work(unsigned& life) const override;

	Miner* clone() const override;
};

