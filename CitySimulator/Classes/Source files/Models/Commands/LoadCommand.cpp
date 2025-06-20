#include <Models/Commands/LoadCommand.h>

LoadCommand::LoadCommand(Simulation& simulation, const std::string& fileName)
    : Command(simulation), fileName(fileName) { }

bool LoadCommand::execute()
{
    return false;
}
