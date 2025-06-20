#pragma once

#include <Models/Entities/Citizen.h>

class Profession
{
public:
	Profession(Citizen& citizen, unsigned minSalary, unsigned maxSalary);

	unsigned getSalary() const;
	
	virtual void work() const = 0;

	virtual Profession* clone(Citizen& citizen) const = 0;

	virtual const std::string getInfoString() const;

protected:
	Citizen& citizen;

private:
	unsigned salary;

	void setSalary(unsigned minSalary, unsigned maxSalary);
};

int min(int first, int second);
int max(int first, int second);

