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

int main() {
    CLHEP::MTwistEngine myEngine = CLHEP::MTwistEngine();

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10; ++i) {
        std::string filename = "status" + std::to_string(i) + ".txt";
        myEngine.restoreStatus(filename.c_str());

        double pi = monteCarloPi(myEngine, 1000000000LL);
        std::cout << "Estimation of PI: " << pi << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}