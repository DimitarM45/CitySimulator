#include <Models/Entities/Miner.h>

namespace MinerConstants
{
	constexpr unsigned MINER_MIN_SALARY = 1000;
	constexpr unsigned MINER_MAX_SALARY = 3000;
}

using namespace MinerConstants;

Miner::Miner()
	: Profession(MINER_MIN_SALARY, MINER_MAX_SALARY) { }

void Miner::work(unsigned& life) const
{
	life = max(0, life - 1);
}

Miner* Miner::clone() const
{
	return new Miner(*this);
}
