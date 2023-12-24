#include "Random/MTwistEngine.h"
#include <iostream>
#include <chrono>
#include <omp.h>

double monteCarloPi(CLHEP::MTwistEngine& engine, long long numPoints) {
    long long inCircle = 0;
    #pragma omp parallel for reduction(+:inCircle)
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
    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        CLHEP::MTwistEngine myEngine;
        std::string filename = "status" + std::to_string(i) + ".txt";
        myEngine.restoreStatus(filename.c_str());

        double pi = monteCarloPi(myEngine, 1000000000LL);
        #pragma omp critical
        {
            std::cout << "Estimation of PI: " << pi << std::endl;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}