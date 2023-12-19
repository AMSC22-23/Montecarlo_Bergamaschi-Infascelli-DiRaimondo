#ifndef HYPERRECTANGLE_HPP
#define HYPERRECTANGLE_HPP

#include <iostream>
#include <vector>
#include <string> 
#include <cmath>
#include <cstdlib>
#include "omp.h"
#include "Domain.hpp"
#include  <fstream>

class HyperRectangle : public Domain{

    private:
        std::vector<PuntiAssi> cord; 
        
    public:
    //@note: shoudl pass by const **reference**
    HyperRectangle(const std::string inputFile);

    //@note: should be const (and other below)
    int 
    const getDimensionDomain();

    double
    const getVolume();

    double
    generateRandomPoint();

    std::vector<double>
    const getPoint();

    std::string 
    const getFunction();

};
#endif