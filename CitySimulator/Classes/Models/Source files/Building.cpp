#include "../Header files/Building.h"

#include <cmath>

namespace BuildingConstants
{
	const unsigned CENTRAL_RENT_MULTIPLIER = 2.5;
	const unsigned SUBURBAN_RENT_MULTIPLIER = 0.2;
}

using namespace BuildingConstants;

Building::Building(unsigned denizenCount, unsigned xIndex, unsigned yIndex, unsigned rent)
	: denizenCount(denizenCount), xIndex(xIndex), yIndex(yIndex)
{
	this->isCentral = isCentralBuilding(xIndex, yIndex);
	setRent(rent);
}

void Building::simulateDay()
{
	for (size_t i = 0; i < denizenCount; i++)
	{
		denizens[i].live();
	}
}

unsigned Building::getRent() const
{
	return rent;
}

bool Building::getIsCentral() const
{
	return isCentral;
}

void Building::setRent(unsigned rent)
{
	if (isCentral)
		rent *= CENTRAL_RENT_MULTIPLIER;

	else
		rent -= rent * SUBURBAN_RENT_MULTIPLIER;
}

bool Building::isCentralBuilding(unsigned xIndex, unsigned yIndex)
{
	if (min(xIndex, yIndex) == -1)
	{

	}

}

short min(unsigned xIndex, unsigned yIndex)
{
	if (xIndex < yIndex)
		return -1;

	else if (xIndex > yIndex)
		return 1;

	else
		return 0;
}
