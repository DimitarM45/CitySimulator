#include <Models/Entities/DormBuilding.h>

constexpr unsigned DORM_DEFAULT_RENT = 40;

DormBuilding::DormBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex)
	: Building(denizenCapacity, yIndex, xIndex, DORM_DEFAULT_RENT) { }