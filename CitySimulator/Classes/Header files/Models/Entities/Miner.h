#pragma once

#include <Models/Entities/Profession.h>

class Miner : public Profession
{
public:
	Miner(Citizen& citizen);

	void work() const override;

	Miner* clone(Citizen& citizen) const override;

	const std::string getInfoString() const override;
};

