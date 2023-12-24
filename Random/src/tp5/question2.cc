/**
 * @file question2.cc
 * @brief This program demonstrates the usage of the CLHEP::MTwistEngine random number generator.
 * 
 * The program generates random numbers using the MTwistEngine and saves/restores the status of the generator.
 * It prints the first 10 random numbers, saves the status, generates 10 more random numbers, restores the status,
 * and generates 10 more random numbers. The last set of random numbers should be the same as the second set.
 */

#include "CLHEP/Random/MTwistEngine.h"
#include <iostream>
#include <fstream>

int main() 
{
    // Create a new random number generator
    CLHEP::MTwistEngine myEngine = CLHEP::MTwistEngine();

    std::cout << "=> The first 10 random numbers generated:" << std::endl;

    for (int i = 0; i < 10; ++i) 
    {
        std::cout << myEngine.flat() << " ";
    }

    std::cout << std::endl;

    myEngine.saveStatus("status.txt");

    std::cout << "=> The 10 random numbers after saving the status:" << std::endl;

    for (int i = 0; i < 10; ++i) 
    {
        std::cout << myEngine.flat() << " ";
    }
    
    myEngine.restoreStatus("status.txt");

    std::cout << "=> The 10 random numbers after restoring the status:" << std::endl;

    for (int i = 0; i < 10; ++i) 
    {
        std::cout << myEngine.flat() << " ";
    }
  
    return 0;
}