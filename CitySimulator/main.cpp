#include <iostream>

#include <Services/SimulationManager.h>

int main()
{
	// simulation manager works with text files, console or both to read commands and serialize them
	// (either in the console or in a text file)
	SimulationManager simManager(std::cout, std::cin, "history.bin");
	simManager.run();
}