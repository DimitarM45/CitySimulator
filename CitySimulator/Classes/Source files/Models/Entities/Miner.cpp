#include <Models/Entities/Miner.h>

Miner::Miner(const std::string& name, Building& building, unsigned happiness, unsigned money, unsigned lifePoints)
	: Citizen(name, building, happiness, money, lifePoints) { }

void Miner::live(unsigned dateDay)
{
}

bool Miner::serialize(const std::string& fileName) const
{
	return false;
}

bool Miner::deserialize(const std::string& fileName) const
{
	return false;
}
