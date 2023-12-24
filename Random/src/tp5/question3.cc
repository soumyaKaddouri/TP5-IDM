/**
 * @file question3.cc
 * @brief This program demonstrates the usage of the CLHEP::MTwistEngine random number generator.
 * 
 * The program generates 2 billion random numbers in 10 iterations (200 million per iteration) using the MTwistEngine.
 * After each iteration, it saves the status of the generator to a file. The status files can be used to restore the 
 * generator to a previous state.
 */

#include "CLHEP/Random/MTwistEngine.h"
#include <iostream>
#include <fstream>

int main() 
{
    CLHEP::MTwistEngine myEngine = CLHEP::MTwistEngine();

    for (int i = 0; i < 10; ++i) 
    {
        for (long long j = 0; j < 2000000000LL; ++j) 
        {
            myEngine.flat();
        }

        // Save the status of the generator
        std::string filename = "status" + std::to_string(i) + ".txt";

        myEngine.saveStatus(filename.c_str());
    }

    return 0;
}