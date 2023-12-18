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
        //@note: shoudl pass by const reference
        HyperSphere(const string inputFile);

        //@note: should be const
        int 
        getDimensionDomain();

        //@note: should be const
        double
        getVolume();

        double
        generateRandomPoint();

        //@note: should be const
        double
        getRadius();

        //@note: should be const
        vector<double>
        getPoint();
        
        //@note: should be const
        string
        getFunction();

};
#endif