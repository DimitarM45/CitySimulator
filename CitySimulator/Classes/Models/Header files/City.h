#pragma once

#include "Building.h"
#include "../../Utilities/Header files/Matrix.h"

#include <ctime>
#include <vector>

class City
{
public:
	City();
	City(const City& other);
	City& operator=(const City& other);
	~City();

private:
	Matrix<Building> buildings;
};

