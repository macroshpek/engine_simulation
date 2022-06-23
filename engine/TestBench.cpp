#include "TestBench.h"
#include <iostream>

#define MAX_TIME 3600
#define EPSILON 0.00001

void TestBench::testEngineOverheat(Engine& engine)
{
    double elapsedTime = engineSimulation(engine);
    if (elapsedTime >= MAX_TIME - EPSILON) {
        logger.printTestInfo(elapsedTime, (char*)"did not overheat in the maximum time");
    }
    else {
        logger.printTestInfo(elapsedTime, (char*)"overheated");
    }
}

double TestBench::engineSimulation(Engine& engine)
{
    double T_environment = logger.getAmbientTemperature();
    double T_engine{};
    double timeStep = 0.01;
    double elapsedTime = 0;

    elapsedTime = 0;
    T_engine = T_environment;

    while (T_engine < engine.getOverheatingTemperature() - EPSILON && elapsedTime < MAX_TIME)
    {

        engine.V += engine.getAcceleration() * timeStep;

        T_engine += (engine.getEngineHeatingRate() + engine.getEngineCoolingRate(T_environment, T_engine)) * timeStep;

        elapsedTime += timeStep;
        std::cout << T_engine << "\t" << elapsedTime << "\t" << engine.V << std::endl;

    }
    return elapsedTime;
}


