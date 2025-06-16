#include <Models/Commands/InfoCommand.h>

InfoCommand::InfoCommand(Simulation& simulation, unsigned yIndex, unsigned xIndex, const std::string* name)
	: Command(simulation), yIndex(yIndex), xIndex(xIndex), name(name) { }

bool InfoCommand::execute()
{
	if (!name && yIndex == -1 && xIndex == -1)
	{
		simulation.getCity()
	}
}

std::string InfoCommand::serializeOutput()
{
	return 
}
