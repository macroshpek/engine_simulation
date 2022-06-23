#include <iostream>
#include "Engine.h"
#include "TestBench.h"
#include <vector>

int main() 
{
    InternalCombustionEngine engine;

    TestBench bench{};

    bench.testEngineOverheat(engine);

    return 0;
}


