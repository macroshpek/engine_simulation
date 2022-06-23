#pragma once
#include "Engine.h"
#include "ConsoleLogger.h"

class TestBench
{
public:
	void testEngineOverheat(Engine& engine);
	double engineSimulation(Engine& engine);
	ConsoleLogger logger;
};