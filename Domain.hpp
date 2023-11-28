#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>

#ifndef MONTECARLO_H
#define MONTECARLO_H

using namespace std;
class Domain {
    
    private : 
    int nDimension; 

    public : 

    Domain() = default; 

    Domain(int nDim){
        nDimension = nDim; 
    };

    virtual int getDimensionDomain() = 0; 
    virtual double getVolume() = 0; 
    virtual void generateRandomPoint() = 0;
};
#endif //MONTECARLO_H
