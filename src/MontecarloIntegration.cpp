#include <iostream>
#include <cmath>
#include <random>
#include "Domain.hpp"
using namespace std;

class MontecarloIntegration{
private:
    double integral = 0.0;

public:

    double integrate(unique_ptr<Domain> &, int);
    
    double getIntegral(){
        return integral;
    }
};


double MontecarloIntegration::integrate(unique_ptr<Domain> &d, int samples){
    
    double sum =0 ; 
    vector<double> point; 
    // compute the volume of the geometric form
    double volume = 0.0; //gli passo il volume della forma geometrica

    //conviene fare una classe astratta per una generica forma geometrica? oppure if else
    //the number of samples should be taken from the command line (?)
    for(int k = 0; k < samples; k++){

        if(d->generateRandomPoint() != -1){
            point = d->getPoint();
            for(int j = 0; j < point.size(); j++){
                cout << point[j] << endl;
            }
        }
        //se non sono entrata nell'if significa che il punto non sta nel dominio
    }

    return 0; 
}