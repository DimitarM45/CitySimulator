#include <iostream>

#include <Services/SimulationManager.h>

int main()
{
	// Used to seed BuildingSeeder and CitizenSeeder
	std::srand(std::time(nullptr));

	// simulation manager works with text files, console or both to read commands and serialize them
	// (either in the console or in a text file)
	SimulationManager simManager(std::cout, std::cin);
	simManager.run();
}