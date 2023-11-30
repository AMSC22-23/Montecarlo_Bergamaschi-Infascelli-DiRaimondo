#include <iostream>
#include <fstream>
#include <string>
#include "HyperRectangle.cpp"
#include "HyperSphere.cpp"
#include "MontecarloIntegration.cpp"    //da cambiare con hpp?
#include "Domain.hpp"

using namespace std;
int main(int argc, char** argv){
    int type_domain = 0;
    int numSamples = 0;
    double x; 
    Domain *h; 
    

//cout << argv[0] << endl;
//cout << argv[1] << endl;
//cout << argv[2] << endl;
//cout << argv[3] << endl;

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
        //passare dei parametri
        h = new HyperSphere(argv[1]);
        h->generateRandomPoint();

    }
    else{       
        //hyperRectangle
         h = new HyperRectangle(argv[1]);
    }

    numSamples = atoi(argv[3]);
    if(numSamples < 0){
        cout << "Invalid parameter for the number of samples" << endl;
        return -1;
    }
   

    MontecarloIntegration m;
    //da sistemare, bisogna aggiungere funzione e dominio

    double res = m.integrate( h ,numSamples);
    cout << "The integral of the function using Montecarlo integration is " << endl;
    cout << res << endl;

    return 0;
} 
