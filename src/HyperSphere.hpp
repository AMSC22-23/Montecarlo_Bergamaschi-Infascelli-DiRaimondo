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

struct Range {
    double x,y; 
}; 
    private:
        double r = 0.0;   //radius
        vector<double> center;
        int dimensions = 0, numIn=0, numTot=0;
        double x,sum; 
        double rv = 0.0;
        mt19937 re{random_device{}()};
        vector<Range> cord;
        vector<double> point;
        string function; 
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