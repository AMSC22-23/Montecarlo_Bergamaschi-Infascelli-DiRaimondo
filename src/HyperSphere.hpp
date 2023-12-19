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
        //@note: shoudl pass by const **reference**
        HyperSphere(const std::string inputFile);

        //@note: should be const
        //       the method should be const, not the returned object
        //       In the current way you are just saying that what you return is a const
        //       which does not really add much
        //       If you make the method const (`const` after the name), you make it so that
        //       the method cannot change the class, which is a good constraint for many cases
        int 
        const getDimensionDomain();

        //@note: should be const
        double
        const getVolume();

        double
        generateRandomPoint();

        //@note: should be const
        double
        getRadius();

        //@note: should be const
        std::vector<double>
        const getPoint();

        //@note: should be const
        std::string
        const getFunction();

};
#endif