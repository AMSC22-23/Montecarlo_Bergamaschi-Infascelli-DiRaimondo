#include "HyperRectangle.hpp"

HyperRectangle::HyperRectangle(std::string inputFile)
{
    std::ifstream input(inputFile);
    if (!input.is_open()) {
        throw std::runtime_error("Error opening input file: "+ inputFile);
    }

    input >> dimensions; 
                
    if(dimensions <= 0){
        throw std::invalid_argument("The value of the dimension is not valid");
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
const HyperRectangle::getDimensionDomain() 
{
    return dimensions;
}

double 
const HyperRectangle::getVolume()  
{
    double totVol = 1; 

    for(int i = 0; i < dimensions; i++){
        totVol = totVol * std::abs(cord[i].x - cord[i].y); 
    }

    return totVol;
}

double 
HyperRectangle::generateRandomPoint()
{     
    point.reserve(dimensions);
    point.resize(dimensions);
        
    //this for takes 1 element for each coordinate of a single point
    for(int j = 0; j < dimensions; j++){
        std::uniform_real_distribution<double> distribution(cord[j].x, cord[j].y);
        point[j] = distribution(re);
    }

    return 1; 
}
std::vector<double> 
const HyperRectangle::getPoint()
{
    return point;
}

std::string 
const HyperRectangle::getFunction()
{
    return function;
}

