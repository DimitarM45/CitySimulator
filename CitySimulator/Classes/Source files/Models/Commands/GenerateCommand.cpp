#include <Services/Simulation.h>
#include <Models/Commands/GenerateCommand.h>

GenerateCommand::GenerateCommand(Simulation& simulation, unsigned length, unsigned width)
	: Command(simulation) {
}

bool GenerateCommand::execute()
{
	simulation.seed(length, width);

	output = simulation.getDate().getDateString();
}