#pragma once

#include <string>

using string = std::string;

class Profession
{
public:
	Profession();
	Profession(const Profession& other);
	Profession& operator=(const Profession& other);
	~Profession();

	

private:
	string name;
	unsigned pay;
};

