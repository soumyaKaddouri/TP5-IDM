#include "CLHEP/Random/MTwistEngine.h"
#include <iostream>
#include <fstream>

int main() {
    CLHEP::MTwistEngine myEngine = CLHEP::MTwistEngine();

    // Generate 2 billion random numbers and save the status after each billion
    for (int i = 0; i < 10; ++i) {
        for (long long j = 0; j < 2000000000LL; ++j) {
            myEngine.flat();
        }

        // Save the status of the generator
        std::string filename = "status" + std::to_string(i) + ".txt";
        myEngine.saveStatus(filename.c_str());
    }

    return 0;
}