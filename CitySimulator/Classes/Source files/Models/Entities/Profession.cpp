#include <Models/Entities/Citizen.h>
#include <Models/Entities/Profession.h>

#include <ctime>
#include <random>

Profession::Profession(Citizen& citizen, unsigned minSalary, unsigned maxSalary)
    : citizen(citizen)
{
    setSalary(minSalary, maxSalary);
}

unsigned Profession::getSalary() const
{
    return salary;
}

int min(int first, int second)
{
    return first <= second ? first : second;
}

int max(int first, int second)
{
    return first >= second ? first : second;
}

void Profession::setSalary(unsigned minSalary, unsigned maxSalary)
{
    salary = rand() % (maxSalary - minSalary + 1) + minSalary;
}

const std::string Profession::getInfoString() const
{
    return "Salary: " + std::to_string(salary);
}