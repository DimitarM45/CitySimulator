#include <Models/Entities/Programmer.h>

namespace ProgrammerConstants
{
	constexpr unsigned MIN_PROGRAMMER_SALARY = 2000;
	constexpr unsigned MAX_PROGRAMMER_SALARY = 5000;
}

using namespace ProgrammerConstants;

Programmer::Programmer()
	: Profession(MIN_PROGRAMMER_SALARY, MAX_PROGRAMMER_SALARY) { }

void Programmer::work(unsigned& happiness) const
{
	happiness = max(0, happiness - 1);
}

Programmer* Programmer::clone() const
{
	return new Programmer(*this);
}
