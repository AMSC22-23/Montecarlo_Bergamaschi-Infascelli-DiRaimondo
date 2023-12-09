#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>

using namespace std;
class Domain {

    protected:
    mt19937 re{random_device{}()};
    int dimensions = 0;
    string function; 
    vector<double> point;


    struct Coordinates {
        double x,y; 
    }; 

    public : 

    Domain() = default; 

    Domain(int nDim){
        dimensions = nDim; 
    };
    virtual ~Domain() = default;

    virtual int getDimensionDomain() = 0; 
    virtual double getVolume() = 0; 
    virtual double generateRandomPoint() = 0;
    virtual vector<double> getPoint() = 0;
    virtual string getFunction() = 0;
};
#endif //DOMAIN_H
