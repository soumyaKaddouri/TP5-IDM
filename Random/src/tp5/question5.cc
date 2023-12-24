/**
 * @file question5.cc
 * @brief This program uses the Monte Carlo method to estimate the value of PI.
 * 
 * The program uses the CLHEP::MTwistEngine random number generator to generate random points within a unit square.
 * It then counts the number of points that fall within a quarter of a unit circle. The ratio of the points within the
 * circle to the total number of points is an estimate of PI/4, so the program multiplies this ratio by 4 to get an
 * estimate of PI.
 * 
 * The program restores the state of the random number generator from a file specified as a command-line argument.
 * It then performs the PI estimation and prints the result.
 */

#include "CLHEP/Random/MTwistEngine.h"
#include <iostream>
#include <chrono>

/**
 * @brief Estimate the value of PI using the Monte Carlo method.
 * 
 * @param engine The random number generator.
 * @param numPoints The number of random points to generate.
 * @return An estimate of PI.
 */

double monteCarloPi(CLHEP::MTwistEngine& engine, long long numPoints) 
{
    long long       inCircle = 0;

    for (long long i = 0; i < numPoints; ++i) 
    {
        double x = engine.flat();
        double y = engine.flat();

        if (x*x + y*y <= 1.0) 
        {
            ++inCircle;
        }
    }

    return 4.0 * inCircle / numPoints;
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <status file>\n";
        return 1;
    }

    CLHEP::MTwistEngine     myEngine;
    double                  pi;

    myEngine.restoreStatus(argv[1]);

    pi = monteCarloPi(myEngine, 1000000000LL);
    std::cout << pi << std::endl;

    return 0;
}