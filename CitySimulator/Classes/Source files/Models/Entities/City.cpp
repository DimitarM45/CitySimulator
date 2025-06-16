#include <Models/Entities/City.h>

City::City()
{
}

Building& City::getBuilding(unsigned yIndex, unsigned xIndex)
{
	return buildings[yIndex][xIndex];
}

unsigned City::getLength() const
{
	return buildings.getLength();
}

unsigned City::getWidth() const
{
	return buildings.getWidth();
}

std::string City::getInfoString()
{
	std::string infoString;

	city
}
