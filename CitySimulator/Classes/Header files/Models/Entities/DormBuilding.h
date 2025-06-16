#pragma once

#include <Models/Entities/Building.h>

class DormBuilding : public Building
{
public:
	DormBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex);
};

