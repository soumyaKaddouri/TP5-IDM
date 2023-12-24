#include "CLHEP/Random/MTwistEngine.h"
#include <iostream>
#include <fstream>

int main() {
    CLHEP::MTwistEngine myEngine = CLHEP::MTwistEngine();
    //myEngine.setSeed(12345, 23); // Set a seed for the random number generator

    // Generate 10 random numbers and print them
    std::cout << std::endl;
    std::cout << "=> The first 10 random numbers generated:" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << myEngine.flat() << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    // Save the status of the generator
    myEngine.saveStatus("status.txt");

    // Generate 10 more random numbers and print them
    std::cout << "=> The 10 random numbers after saving the status:" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << myEngine.flat() << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    // Restore the status of the generator
    myEngine.restoreStatus("status.txt");

    // Generate 10 more random numbers and print them
    // These should be the same as the second set of 10 numbers
    std::cout << "=> The 10 random numbers after restoring the status:" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << myEngine.flat() << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}