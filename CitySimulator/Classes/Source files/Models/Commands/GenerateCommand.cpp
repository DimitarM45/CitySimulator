#include <Services/Simulation.h>
#include <Models/Commands/GenerateCommand.h>

GenerateCommand::GenerateCommand(Simulation& simulation, SeedOption seedOption)
	: Command(simulation) { }

bool GenerateCommand::execute()
{
	simulation.configure(seedOption);

	return true;
}

std::string GenerateCommand::serializeOutput()
{
	return simulation.getDate().getDateString();
}
