#include "CLHEP/Random/MTwistEngine.h"
#include <iostream>
#include <chrono>

double monteCarloPi(CLHEP::MTwistEngine& engine, long long numPoints) {
    long long inCircle = 0;
    for (long long i = 0; i < numPoints; ++i) {
        double x = engine.flat();
        double y = engine.flat();
        if (x*x + y*y <= 1.0) {
            ++inCircle;
        }
    }
    return 4.0 * inCircle / numPoints;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <status file>\n";
        return 1;
    }

    CLHEP::MTwistEngine myEngine;
    myEngine.restoreStatus(argv[1]);

    double pi = monteCarloPi(myEngine, 1000000000LL);
    std::cout << pi << std::endl;

    return 0;
}