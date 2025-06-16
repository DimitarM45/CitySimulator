#include <Models/Entities/Profession.h>

#include <ctime>
#include <random>

Profession::Profession(unsigned minSalary, unsigned maxSalary)
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
    std::srand(std::time(nullptr));

    salary = rand() % (maxSalary - minSalary + 1) + minSalary;
}