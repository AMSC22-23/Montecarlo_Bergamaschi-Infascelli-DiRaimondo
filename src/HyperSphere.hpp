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

class HyperSphere : public Domain{
    private:
        double r = 0.0;   //radius
        std::vector<double> center;
        double x,sum; 
        double rv = 0.0;
        std::vector<PuntiAssi> cord;
        double var_x; 

    public:
        HyperSphere(const std::string inputFile);

        int 
        const getDimensionDomain();

        double
        const getVolume();

        double
        generateRandomPoint();

        double
        getRadius();

        std::vector<double>
        const getPoint();

        std::string
        const getFunction();

};
#endif