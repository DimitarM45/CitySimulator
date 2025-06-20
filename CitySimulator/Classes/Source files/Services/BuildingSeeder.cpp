#include <Services/BuildingSeeder.h>

#include <Models/Entities/Building.h>
#include <Models/Entities/DormBuilding.h>
#include <Models/Entities/ApartmentBuilding.h>
#include <Models/Entities/ModernBuilding.h>

BuildingSeeder::BuildingSeeder(const CitizenSeeder* citizenSeeder = nullptr)
	: citizenSeeder(citizenSeeder) { } 

Building* BuildingSeeder::getRandom(unsigned yIndex, unsigned xIndex) const
{
	using namespace BuildingConstants;

	BuildingType buildingType = (BuildingType)(rand() % 3);

	Building* building;

	int citizenCapacity = rand() % BuildingConstants::MAX_CITIZEN_CAPACITY + 1;

	switch (buildingType)
	{
	case BuildingType::DormBuilding:
		building = new DormBuilding(citizenCapacity, yIndex, xIndex, *citizenSeeder);
		break;

	case BuildingType::ApartmentBuilding:
		building = new ApartmentBuilding(citizenCapacity, yIndex, xIndex, *citizenSeeder);
		break;

	case BuildingType::ModernBuilding:
		building = new ModernBuilding(citizenCapacity, yIndex, xIndex, *citizenSeeder);
		break;
	}

	return building;
}

void BuildingSeeder::setCitizenSeeder(const CitizenSeeder& citizenSeeder)
{
	this->citizenSeeder = &citizenSeeder;
}
