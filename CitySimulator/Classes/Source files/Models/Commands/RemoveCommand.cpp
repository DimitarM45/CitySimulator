#include <Models/Commands/RemoveCommand.h>

RemoveCommand::RemoveCommand(Simulation& simulation, unsigned yIndex, unsigned xIndex, const std::string& name)
    : Command(simulation), yIndex(yIndex), xIndex(xIndex), name(name), isSuccessful(false) { }

bool RemoveCommand::execute()
{
    return simulation.removeDenizen(yIndex, xIndex, name);
}

std::string RemoveCommand::serializeOutput()
{
    using namespace CommandOutputMessages;

    return isSuccessful ? SUCCESS_OUTPUT_MESSAGE : FAILURE_OUTPUT_MESSAGE;
}
