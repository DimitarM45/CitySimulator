#pragma once

#include <Models/Entities/Building.h>
#include <Utilities/Matrix.h>

class City
{
public:
	City();

	Building* getBuilding(unsigned yIndex, unsigned xIndex);
	
	unsigned getLength() const;
	unsigned getWidth() const;

	std::string getInfoString();

private:
	Matrix<Building> buildings;
};

