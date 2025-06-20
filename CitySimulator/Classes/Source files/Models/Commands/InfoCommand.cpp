#include <Models/Commands/InfoCommand.h>

InfoCommand::InfoCommand(Simulation& simulation, int yIndex, int xIndex, const std::string* citizenName)
	: Command(simulation), yIndex(yIndex), xIndex(xIndex), citizenName(citizenName) {
}

InfoCommand::InfoCommand(Simulation& simulation)
	: InfoCommand(simulation, -1, -1) {
}

bool InfoCommand::execute()
{
	if (!citizenName && yIndex == -1 && xIndex == -1)
	{
		output = simulation.getAllInfo();
	}
	else if (!citizenName && yIndex != -1 && xIndex != -1)
	{
		output = simulation.getBuildingInfo(yIndex, xIndex);
	}
	else
	{
		Building* building = simulation.getBuildings()[yIndex][xIndex];

		if (!building)
			return false;

		Citizen* citizen = building->getCitizen(*citizenName);

		if (!citizen)
			return false;

		output = citizen->getInfoString();
	}

	return true;
}
