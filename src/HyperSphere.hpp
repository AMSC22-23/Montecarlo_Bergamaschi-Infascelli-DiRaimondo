#ifndef HYPERSPHERE_HPP
#define HYPERSPHERE_HPP

#include <iostream>
#include <vector>
#include <string> 
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <random>
#include "Domain.hpp"
#include "omp.h"

using namespace std;

class HyperSphere : public Domain{
    private:
        double r = 0.0;   //radius
        vector<double> center;
        double x,sum; 
        double rv = 0.0;
        vector<Coordinates> cord;
        double var_x; 

    public:
        HyperSphere(const string inputFile);

        int 
        getDimensionDomain();

        double
        getVolume();

        double
        generateRandomPoint();

        double
        getRadius();

        vector<double>
        getPoint();

        string
        getFunction();

};
#endif