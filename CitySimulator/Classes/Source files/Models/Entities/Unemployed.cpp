#include <Models/Entities/Unemployed.h>

Unemployed::Unemployed(Citizen& citizen)
	: Profession(citizen, 0, 0) { }

void Unemployed::work() const
{
	citizen.setLifePoints(max(0, citizen.getLifePoints() - 1));
}

Unemployed* Unemployed::clone(Citizen& citizen) const
{
	return new Unemployed(citizen);
}

const std::string Unemployed::getInfoString() const
{
	std::string infoString("Unemployed ");

	return infoString.append(Profession::getInfoString());
}
