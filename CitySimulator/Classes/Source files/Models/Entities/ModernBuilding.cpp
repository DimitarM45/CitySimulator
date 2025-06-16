#include <Models/Entities/ModernBuilding.h>

constexpr unsigned MODERN_DEFAULT_RENT = 1000;

ModernBuilding::ModernBuilding(unsigned denizenCapacity, unsigned yIndex, unsigned xIndex)
	: Building(denizenCapacity, yIndex, xIndex, MODERN_DEFAULT_RENT) { }