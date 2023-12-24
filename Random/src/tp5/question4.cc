/**
 * @file question4.cc
 * @brief This program uses the Monte Carlo method to estimate the value of PI.
 * 
 * The program uses the CLHEP::MTwistEngine random number generator to generate random points within a unit square.
 * It then counts the number of points that fall within a quarter of a unit circle. The ratio of the points within the
 * circle to the total number of points is an estimate of PI/4, so the program multiplies this ratio by 4 to get an
 * estimate of PI.
 * 
 * The program performs this estimation 10 times, restoring the state of the random number generator from a file before
 * each estimation. It also measures and prints the total time taken to perform the 10 estimations.
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

int main() 
{
    CLHEP::MTwistEngine myEngine = CLHEP::MTwistEngine();

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10; ++i) 
    {
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