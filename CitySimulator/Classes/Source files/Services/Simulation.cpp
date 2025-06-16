#include <Services/Simulation.h>

City& Simulation::getCity()
{
	return city;
}

bool Simulation::addDenizen(unsigned yIndex, unsigned xIndex, Citizen& denizen)
{
	return city.getBuilding(yIndex, xIndex).addDenizen(denizen);
}

bool Simulation::removeDenizen(unsigned yIndex, unsigned xIndex, const std::string& name)
{
	return city.getBuilding(yIndex, xIndex).removeDenizen(name);
}

unsigned Simulation::getDeadPeopleCount() const
{
	for (size_t y = 0; i < getBuilding; i++)
	{
		for (size_t x = 0; i < length; i++)
		{

		}
	}
}
