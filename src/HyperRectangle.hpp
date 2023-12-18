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

using namespace std;

class HyperRectangle : public Domain{

    private:
        vector<Coordinates> cord; 
        
    public:
    //@note: shoudl pass by const reference
    HyperRectangle(string inputFile);

    //@note: should be const (and other below)
    int 
    getDimensionDomain();

    double
    getVolume();

    double
    generateRandomPoint();

    vector<double>
    getPoint();

    string 
    getFunction();

};
#endif