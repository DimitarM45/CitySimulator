#pragma once

#include <Models/Entities/Building.h>

class ApartmentBuilding : public Building
{
public:
	ApartmentBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex);
};

