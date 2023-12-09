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

    #pragma omp parallel for num_threads(dimensions) shared(cord)
    for(int i = 0; i < dimensions; i++){
        //vedere se atomic è necessario
        #pragma omp atomic
        totVol = totVol * abs(cord[i].x - cord[i].y); 
    }
    #pragma omp barrier

    return totVol;
}

double 
HyperRectangle::generateRandomPoint()
{     
    point.reserve(dimensions);
    point.resize(dimensions);
        
    //this for takes 1 element for each coordinate of a single point
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

