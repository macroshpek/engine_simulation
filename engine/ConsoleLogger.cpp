#include <iostream>
#include "ConsoleLogger.h"

double ConsoleLogger::getAmbientTemperature()
{
	double T_environment{};

	std::cout << "Enter ambient temperature" << std::endl;
	std::cin >> T_environment;

	return T_environment;
}

void ConsoleLogger::printTestInfo(double seconds, char* typeInfo)
{
	std::cout << typeInfo << std::endl;
	std::cout << seconds << std::endl;
}
