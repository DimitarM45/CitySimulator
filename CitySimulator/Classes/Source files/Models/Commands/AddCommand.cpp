#include <Models/Commands/AddCommand.h>

#include <Models/Entities/Miner.h>
#include <Models/Entities/Teacher.h>
#include <Models/Entities/Programmer.h>
#include <Models/Entities/Unemployed.h>

AddCommand::AddCommand(Simulation& simulation, unsigned yIndex, unsigned xIndex, const std::string& citizenName, Profession job, unsigned happiness, unsigned money, unsigned lifePoints)
	: Command(simulation), citizenName(citizenName), yIndex(yIndex), xIndex(xIndex), happiness(happiness), money(money), lifePoints(lifePoints), isSuccessful(false) {
}

bool AddCommand::execute()
{
	try
	{
		Building* building = simulation.getCity().getBuilding(yIndex, xIndex);

		if (!building)
			return false;

		Citizen* citizen = nullptr;

		switch (profession)
		{
		case Profession::Teacher:
			citizen = new Teacher(citizenName, *building, happiness, money, lifePoints);
			break;

		case Profession::Miner:
			citizen = new Miner(citizenName, *building, happiness, money, lifePoints);
			break;

		case Profession::Programmer:
			citizen = new Programmer(citizenName, *building, happiness, money, lifePoints);
			break;

		case Profession::Unemployed:
			citizen = new Unemployed(citizenName, *building, happiness, money, lifePoints);
			break;
		}

		isSuccessful = simulation.addDenizen(yIndex, xIndex, *citizen);

		delete citizen;

		return isSuccessful;
	}
	catch (...)
	{
		return false;
	}
}

std::string AddCommand::serializeOutput()
{
	using namespace CommandOutputMessages;

	return isSuccessful ? SUCCESS_OUTPUT_MESSAGE : FAILURE_OUTPUT_MESSAGE;
}
