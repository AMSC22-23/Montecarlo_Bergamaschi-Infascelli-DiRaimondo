#ifndef HYPERRECTANGLE_HPP
#define HYPERRECTANGLE_HPP

#include <iostream>
#include <vector>
#include <string> 
#include <cmath>
#include <cstdlib>
#include "Domain.hpp"
#include  <fstream>

using namespace std;

class HyperRectangle : public Domain{
    struct Edges {
        double x,y; 
    }; 

    private:
        int dimensions; 
        vector<Edges> cord; 
        mt19937 re{random_device{}()};
        vector<double> point;
        string function;
    public:
    HyperRectangle(string inputFile);

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