#include <Models/Entities/ApartmentBuilding.h>

constexpr unsigned APARTMENT_DEFAULT_RENT = 500;

ApartmentBuilding::ApartmentBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex)
	: Building(denizenCapacity, yIndex, xIndex, APARTMENT_DEFAULT_RENT) { }
