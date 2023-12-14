#ifndef MONTECARLOINTEGRATION_HPP
#define MONTECARLOINTEGRATION_HPP

#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include "Domain.hpp"
#include <memory>
#include "muParser.h"

class MontecarloIntegration{
    private:
    double integral = 0.0;

    public:
    
    double 
    getIntegral();

    double 
    integrate(unique_ptr<Domain> &d, int samples);
};
#endif