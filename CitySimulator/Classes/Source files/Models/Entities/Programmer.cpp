#include <Models/Entities/Programmer.h>
#include <Models/Entities/Citizen.h>

namespace ProgrammerConstants
{
	constexpr unsigned MIN_PROGRAMMER_SALARY = 2000;
	constexpr unsigned MAX_PROGRAMMER_SALARY = 5000;
}

using namespace ProgrammerConstants;

Programmer::Programmer(Citizen& citizen)
	: Profession(citizen, MIN_PROGRAMMER_SALARY, MAX_PROGRAMMER_SALARY) { }

void Programmer::work() const
{
	citizen.setHappiness(max(0, citizen.getHappiness() - 1));
}

Programmer* Programmer::clone(Citizen& citizen) const
{
	return new Programmer(citizen);
}

const std::string Programmer::getInfoString() const
{
	std::string infoString("Programmer ");

	return infoString.append(Profession::getInfoString());
}
