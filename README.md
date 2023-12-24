# CLHEP Monte Carlo Simulation - TP5

## Description

This repository contains the source code and report for a practical session (TP) focused on utilizing the CLHEP library for high-energy physics simulations. The primary goal was to familiarize ourselves with this library and perform distributed stochastic calculations. The report details our approach and the results obtained throughout the various tasks.

## Installation of CLHEP Library

We meticulously followed the instructions to install the CLHEP library. This involved locating different parts of the library, compiling, and linking it. We verified the installation by checking the date of the obtained files. Testing was performed using provided C++ codes, including `testRandom.cc`.

## Archiving and Restoring Mersenne Twister Generator States

We utilized the `saveStatus` method to archive Mersenne Twister (MT) generator states. Restoration using the `restoreStatus` method allowed us to reproduce specific pseudo-random sequences, crucial for debugging and result reproducibility.

## Saving 10 States of the Mersenne Twister Generator

A code was implemented to save 10 distinct states of the MT generator. The code generated 2 billion random numbers, saved the current state after each set, and named the status files accordingly.
This code can be found in `Random/src/tp5/question2.cc`

## Monte Carlo PI Calculation with State Restoration

We developed a code to consecutively execute 10 replications of a Monte Carlo PI calculation. The 2 billion numbers required for each replication were pre-calculated by saving the MT generator states. The sequential runtime was measured and compared on two different machines.
Saving the MT generator states : `Random/src/tp5/question3.cc`
Calculation using the saved states : `Random/src/tp5/question4.cc`

## Parallelization of Monte Carlo Replications for PI Calculation

In this phase, we parallelized the execution using "sequence splitting" to simultaneously calculate 10 replications of a Monte Carlo simulation for PI estimation. A Bash script launched 10 instances of the C++ program in the background, each with a different status file.
C++ program : `Random/src/tp5/question5.cc`
Bash script : `Random/src/tp5/launch_script.sh`

## Conclusion

The TP explored various aspects of stochastic simulation using CLHEP, including archiving/restoring generator states and parallelization for PI calculations. We installed CLHEP, saved distinct states, and achieved reproducibility in sequential and parallel executions. Future work may involve exploring alternative parallelization techniques such as OpenMP for more complex simulations.

## Source Files

All source files for the questions can be found in the `Random/src/tp5/` folder.
