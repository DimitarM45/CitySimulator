#pragma once

#include "Building.h"

#include <ctime>
#include <vector>

using std::vector;

class City
{
public:
	City();
	City(const City& other);
	City& operator=(const City& other);
	~City();

private:
	vector<vector<Building*>> grid;
};

