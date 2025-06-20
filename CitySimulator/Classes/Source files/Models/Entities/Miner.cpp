#include <Models/Entities/Miner.h>

namespace MinerConstants
{
	constexpr unsigned MINER_MIN_SALARY = 1000;
	constexpr unsigned MINER_MAX_SALARY = 3000;
}

using namespace MinerConstants;

Miner::Miner(Citizen& citizen)
	: Profession(citizen, MINER_MIN_SALARY, MINER_MAX_SALARY) { }

void Miner::work() const
{
	citizen.setLifePoints(max(0, citizen.getLifePoints() - 1));
}

Miner* Miner::clone(Citizen& citizen) const
{
	return new Miner(citizen);
}

const std::string Miner::getInfoString() const
{
	std::string infoString("Miner ");

	return infoString.append(Profession::getInfoString());
}
