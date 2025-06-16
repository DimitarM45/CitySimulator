#pragma once

class Profession
{
public:
	Profession(unsigned minSalary, unsigned maxSalary);

	unsigned getSalary() const;
	
	virtual void work(unsigned& value) const = 0;

	virtual Profession* clone() const = 0;

private:
	unsigned salary;

	void setSalary(unsigned minSalary, unsigned maxSalary);
};

int min(int first, int second);
int max(int first, int second);

