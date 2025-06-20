#include <Models/Entities/Teacher.h>

#include <ctime>
#include <random>
#include <Models/Entities/Citizen.h>

namespace TeacherConstants
{
	constexpr unsigned TEACHER_MIN_SALARY = 1200;
	constexpr unsigned TEACHER_MAX_SALARY = 1300;
}

using namespace TeacherConstants;

Teacher::Teacher(Citizen& citizen)
	: Profession(citizen, TEACHER_MIN_SALARY, TEACHER_MAX_SALARY) { }

void Teacher::work() const
{
	citizen.setHappiness(min(citizen.getHappiness() + 1, 100));
}

Teacher* Teacher::clone(Citizen& citizen) const
{
	return new Teacher(citizen);
}

const std::string Teacher::getInfoString() const
{
	std::string infoString("Teacher ");

	return infoString.append(Profession::getInfoString());
}
