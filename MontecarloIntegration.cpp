#include <iostream>
#include <cmath>
#include <random>
#include "Domain.hpp"
using namespace std;

class MontecarloIntegration{
private:
    double integral = 0.0;

public:

    double integrate(Domain *, int);
    
    double getIntegral(){
        return integral;
    }
};


double MontecarloIntegration::integrate(Domain *d, int samples){
    
    double sum =0 ; 
    vector<double> point; 
    // compute the volume of the geometric form
    double volume = 0.0; //gli passo il volume della forma geometrica

    //conviene fare una classe astratta per una generica forma geometrica? oppure if else
    //the number of samples should be taken from the command line (?)
    for(int i=0; i<samples; i++){
         d->generateRandomPoint();
        if(point.size() != 0){
            //usa punto...
        } 
    }

    return 0; 
}