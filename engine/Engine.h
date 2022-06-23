#pragma once

class Engine
{
public:
    double getOverheatingTemperature();
    void setOverheatingTemperature(double newOverheatingTemperature);
    double getM();

    virtual double getEngineHeatingRate() = 0;
    virtual double getEngineCoolingRate(double T_environment, double T_engine) = 0;
    virtual double getAcceleration() = 0;

    double I;       //Moment Of Inertia;
    double overheatingTemperature;       //Overheating Temperature;
    double H_m;     //Heating rate-torque relationship coefficient
    double H_v;     //Heating rate crankshaft rotation speed coefficient
    double C;       //Cooling rate coefficient as a function of engine and ambient temperature
    double V;       //crankshaft speed
};

class InternalCombustionEngine : public Engine
{

public:
    InternalCombustionEngine();
    double getEngineHeatingRate();
    double getEngineCoolingRate(double T_environment, double T_engine);
    double getAcceleration();
};

