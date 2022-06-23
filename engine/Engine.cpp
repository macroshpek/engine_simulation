#include "Engine.h"

InternalCombustionEngine::InternalCombustionEngine()
{
    I = 10;
    overheatingTemperature = 110;
    H_m = 0.01;
    H_v = 0.0001;
    C = 0.1;
    V = 0;
}

double InternalCombustionEngine::getEngineHeatingRate()
{
    return getM() * H_m + V * V * H_v;
}

double InternalCombustionEngine::getEngineCoolingRate(double T_environment, double T_engine)
{
    return C * (T_environment - T_engine);
}

double InternalCombustionEngine::getAcceleration()
{
    return getM() / I;
}

double Engine::getM()
{
    if (0.000 <= V && V < 75.000) { 
        return 20 + 0.7333 * (V);
    }
    else if (75.000 <= V && V < 150.000) {
        return 75 + 0.3333 * (V - 75);
    }
    else if (150.000 <= V && V < 200.000) { 
        return 100 + 0.100 * (V - 150);
    }
    else if (200.000 <= V && V < 250.000) { 
        return 105 - 0.600 * (V - 200);
    }
    else if (250.000 <= V && V < 300.000) { 
        return 75 - 1.500 * (V - 250);
    }
    else if (V >= 300.000) { 
        return 0;
    }
}

double Engine::getEngineHeatingRate()
{
    return getM() * H_m + V * V * H_v;
}

double Engine::getEngineCoolingRate(double T_environment, double T_engine)
{
    return C*(T_environment - T_engine);
}

double Engine::getAcceleration()
{
    return getM()/I;
}

void Engine::setOverheatingTemperature(double newOverheatingTemperature)
{
    overheatingTemperature = newOverheatingTemperature;
}

double Engine::getOverheatingTemperature()
{
    return overheatingTemperature;
}
