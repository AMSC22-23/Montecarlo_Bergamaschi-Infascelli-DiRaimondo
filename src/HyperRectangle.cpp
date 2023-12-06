#include "HyperRectangle.hpp"

HyperRectangle::HyperRectangle(string inputFile)
{
    ifstream input(inputFile);
    if (!input.is_open()) {
        cout << "Error opening input file: " << inputFile << endl;
        exit(-1);
    }

    input >> dimensions; 
                
    if(dimensions <= 0){
        cout << "The value of the dimension is not valid" << endl;
        exit(-1);
    }

    cord.reserve(dimensions);
    cord.resize(dimensions);

    for(int i = 0; i < dimensions ; i++){
        input >> cord[i].x; 
        input >> cord[i].y; 
    }
    input >> function;   
}

int 
HyperRectangle::getDimensionDomain() 
{
    return dimensions;
}
        
double 
HyperRectangle::getVolume()  
{
    double totVol = 1; 
    for(int i = 0; i < dimensions; i++){
        totVol = totVol * abs(cord[i].x - cord[i].y); 
    }
    return totVol;
}

double 
HyperRectangle::generateRandomPoint()
{     
    point.reserve(dimensions);
    point.resize(dimensions);
        
    //this is to generate a random number (inside the hypercube)

    //  #pragma omp parallel reduction(+:sum)
    //bisogna rendere tutto thread safe perché altrimenti c'è il rischio che più thread creino gli stessi punti
    for(int j = 0; j < dimensions; j++){
        uniform_real_distribution<double> distribution(cord[j].x, cord[j].y);
        point[j] = distribution(re);
    }
    return 1; 
}
vector<double> 
HyperRectangle::getPoint()
{
    return point;
}

string 
HyperRectangle::getFunction()
{
    return function;
}

