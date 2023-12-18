#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>


class Domain {

    protected:
    std::mt19937 re{std::random_device{}()};
    int dimensions = 0;
    std::string function; 
    std::vector<double> point;

    struct PuntiAssi {
        double x,y; 
    }; 

    public : 

    Domain() = default; 

    Domain(int nDim){
        dimensions = nDim; 
    };
    virtual ~Domain() = default;

    virtual const int getDimensionDomain() = 0; 
    virtual const double getVolume() = 0; 
    virtual double generateRandomPoint() = 0;
    virtual const std::vector<double> getPoint() = 0;
    virtual const std::string getFunction() = 0;
};
#endif
