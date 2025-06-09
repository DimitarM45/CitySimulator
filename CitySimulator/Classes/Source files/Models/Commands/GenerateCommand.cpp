#include "../Header files/GenerateCommand.h"

GenerateCommand::GenerateCommand(std::ostream& outStream, Simulation& simulation)
	: Command(outStream), simulation(simulation) { }

bool GenerateCommand::execute()
{
	simulation.configure();
}

void GenerateCommand::serializeOutput()
{
	outStream << simulation.getDate();
}
