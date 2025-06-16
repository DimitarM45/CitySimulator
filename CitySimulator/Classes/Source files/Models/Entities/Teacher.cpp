#include <Models/Entities/Teacher.h>

#include <ctime>
#include <random>

namespace TeacherConstants
{
	constexpr unsigned TEACHER_MIN_SALARY = 1200;
	constexpr unsigned TEACHER_MAX_SALARY = 1300;
}

using namespace TeacherConstants;

Teacher::Teacher()
	: Profession(TEACHER_MIN_SALARY, TEACHER_MAX_SALARY) { }

void Teacher::work(unsigned& happiness) const
{
	happiness = min(happiness + 1, 100);
}

Teacher* Teacher::clone() const
{
	return new Teacher(*this);
}
