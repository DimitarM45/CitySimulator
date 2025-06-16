#include <Models/Commands/InfoCommand.h>

InfoCommand::InfoCommand(Simulation& simulation, int yIndex, int xIndex, const std::string* name)
	: Command(simulation), yIndex(yIndex), xIndex(xIndex), name(name) { }

InfoCommand::InfoCommand(Simulation& simulation)
	: InfoCommand(simulation, -1, -1) { }

bool InfoCommand::execute()
{
	if (!name && yIndex == -1 && xIndex == -1)
	{
		simulation.getCity().getInfoString();
	}
	else if (!name && yIndex != -1 && xIndex != -1)
	{
		simulation.getCity().getBuilding(yIndex, xIndex);
	}
	else
	{
		Citizen* citizen = simulation.getCity().getBuilding(yIndex, xIndex).getDenizen(*name);

		if (!citizen)
			return false;


		citizen->getInfoString();
	}
}

std::string InfoCommand::serializeOutput()
{
	return 
}
