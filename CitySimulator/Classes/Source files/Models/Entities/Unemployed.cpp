#include <Models/Entities/Unemployed.h>

Unemployed::Unemployed()
	: Profession(0, 0) { }

void Unemployed::work(unsigned& life) const
{
	life = max(0, life - 1);
}

Unemployed* Unemployed::clone() const
{
	return new Unemployed(*this);
}
