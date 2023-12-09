#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <memory>
#include "HyperRectangle.hpp" //hpp o cpp
#include "HyperSphere.hpp"
#include "MontecarloIntegration.cpp"
#include "Domain.hpp"
#include "muParser.h"
#include "omp.h"

using namespace std;

int main(int argc, char** argv){
    auto start = std::chrono::high_resolution_clock::now();

    int type_domain = 0;
    int numSamples = 0;
    double x; 
    std::unique_ptr<Domain> d;

    //at least one parameter for the main, one for the input, one for the type of the domain
    // and another one for the numSamples
    if(argc < 4){
        cout << "Not enough parameters as input" << endl;
        return -1;
    }
    //take the type of domain
    type_domain = atoi(argv[2]);

    if(type_domain != 0 && type_domain != 1){
        cout << "Invalid parameter for the type of domain" << endl;
        return -1;
    }

    //for simplicity, we use 0 to indicate the HyperSphere and 1 for the Hyper-rectangle
    if(type_domain == 0){
        //hyperSphere
        d = std::make_unique<HyperSphere>(argv[1]);
    }
    else{       
        //hyperRectangle
        d = std::make_unique<HyperRectangle>(argv[1]);
    }

    numSamples = atoi(argv[3]);
    if(numSamples < 0){
        cout << "Invalid parameter for the number of samples" << endl;
        return -1;
    }

    MontecarloIntegration m;

    double res = 0.0;

    //I use reduction to be sure that res will be updated correctly by each thread
    #pragma omp parallel for reduction(+:res)
        for(int i = 0; i < numSamples; i++){
            res += m.integrate(d ,1);
        }
    #pragma omp barrier

    cout << "The parallel version of the integral is: " << res * (d->getVolume() / (numSamples)) << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Tempo trascorso: " << elapsed_seconds.count() << " secondi\n";
    return 0;
} 
