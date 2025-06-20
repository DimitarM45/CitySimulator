#include <Services/CitizenSeeder.h>

#include <fstream>

namespace CitizenStatusRanges
{
	constexpr unsigned MIN_HAPPINESS = 1;
	constexpr unsigned MAX_HAPPINESS = 50;

	constexpr unsigned MIN_LIFEPOINTS = 1;
	constexpr unsigned MAX_LIFEPOINTS = 30;
}

CitizenSeeder::CitizenSeeder(const std::string& fileName, Building* building)
	: fileName(fileName), building(building) { }

Citizen* CitizenSeeder::getRandom() const
{
	using namespace CitizenStatusRanges;

	std::ifstream inStream;

	inStream.open(fileName);

	if (!inStream.is_open())
		return nullptr;
	
	unsigned namesCount = 0;

	constexpr int bufferSize = 128;

	char buffer[bufferSize];
	
	std::vector<std::string> names;

	while (inStream.getline(buffer, bufferSize))
	{
		namesCount++;
		std::string name = buffer;

		names.push_back(name);
	}

	std::string randomName = names[rand() % namesCount];

	ProfessionType professionType = (ProfessionType)(rand() % 4);

	int happiness = rand() % (MAX_HAPPINESS - MIN_HAPPINESS + 1) + MIN_HAPPINESS;
	int lifePoints = rand() % (MAX_LIFEPOINTS - MIN_LIFEPOINTS + 1) + MIN_LIFEPOINTS;

	return new Citizen(randomName, *building, professionType, happiness, 0, lifePoints);
}

void CitizenSeeder::setBuilding(Building& building)
{
	this->building = &building;
}
