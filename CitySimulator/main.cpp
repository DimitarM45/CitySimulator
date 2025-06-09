#include <iostream>

#include <Services/SimulationManager.h>

int main()
{
	SimulationManager simManager(std::cout, std::cin, "history.bin");
	simManager.run();
}