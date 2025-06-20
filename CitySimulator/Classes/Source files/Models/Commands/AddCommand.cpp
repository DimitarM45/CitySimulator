#include <Models/Commands/AddCommand.h>

#include <Models/Entities/Citizen.h>

AddCommand::AddCommand(Simulation& simulation, int yIndex, int xIndex, const std::string& citizenName, ProfessionType professionType, int happiness, int money, int lifePoints)
	: Command(simulation), citizenName(citizenName), professionType(professionType), yIndex(yIndex), xIndex(xIndex), happiness(happiness), money(money), lifePoints(lifePoints) { }

bool AddCommand::execute()
{
	using namespace CommandOutputMessages;

	try
	{
		Building* building = simulation.getBuildings()[yIndex][xIndex];

		if (!building)
		 	return false;

		Profession* profession = nullptr;

		Citizen citizen(citizenName, *building, professionType, happiness, money, lifePoints);

		if (simulation.addCitizen(yIndex, xIndex, citizen))
		{
			output = SUCCESS_OUTPUT_MESSAGE;
		}
		else
		{
			output = FAILURE_OUTPUT_MESSAGE;
		}

		return true;
	}
	catch (...)
	{
		return false;
	}
}