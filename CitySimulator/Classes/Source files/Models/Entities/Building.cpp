#include <cmath>

#include <Models/Entities/Building.h>

namespace BuildingConstants
{
	const unsigned CENTRAL_RENT_MULTIPLIER = 2.5;
	const unsigned SUBURBAN_RENT_MULTIPLIER = 0.2;
}

Building::Building(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex, unsigned rent)
	: denizenCapacity(denizenCapacity), yIndex(yIndex), xIndex(xIndex)
{
	this->isCentral = isCentralBuilding(yIndex, xIndex);
	setRent(rent);
}

void Building::passDay(unsigned day)
{
	unsigned denizenCount = denizens.size();

	for (size_t i = 0; i < denizenCount; i++)
	{
		denizens[i]->live(day);
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

Citizen* Building::getDenizen(const std::string& name)
{
	unsigned denizenCount = denizens.size();

	for (size_t i = 0; i < denizenCount; i++)
	{
		if (denizens[i]->getName() == name)
			return denizens[i];
	}

	return nullptr;
}

bool Building::addDenizen(Citizen& denizen)
{ 
	if (denizens.size() == denizenCapacity)
		return false;

	denizens.push_back(&denizen);

	return true;
}

bool Building::removeDenizen(const std::string& name)
{
	unsigned denizenCount = denizens.size();

	for (size_t i = 0; i < denizenCount; i++)
	{
		if (denizens[i]->getName() == name)
		{
			denizens[i] = nullptr;

			return true;
		}
	}

	return false;
}

void Building::setRent(unsigned rent)
{
	using namespace BuildingConstants;

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

bool Building::serialize(const std::string& fileName) const
{
	return false;
}

bool Building::deserialize(const std::string& fileName) const
{
	return false;
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
