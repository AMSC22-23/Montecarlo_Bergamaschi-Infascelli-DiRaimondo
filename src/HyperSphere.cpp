#include "HyperSphere.hpp"

//constructor of the HyperSphere
HyperSphere::HyperSphere(const std::string inputFile)
{
    std::ifstream input(inputFile);

    if (!input.is_open()) {
        std::cout << "Error opening input file: " << inputFile << std::endl;
        exit(-1);
    }

    input >> dimensions; 
    input >> r; 

    if(r <= 0.0){
        std::cout << "The value of the radius is not valid " << std::endl;
        std::cout << "The radius is:" << r << std::endl;
        exit(-1);
    }
        
    if(dimensions <= 0){
        std::cout << "The value of the dimension is not valid" << std::endl;
        exit(-1);
    }

    //this for loop is used in order to take the coordinates of the center
    for(int i = 0 ; i < dimensions; i++){
        input >> x; 
        center.emplace_back(x);
    }

    input >> function; 
        
    cord.reserve(dimensions);
    cord.resize(dimensions);

    for(int i=0; i < dimensions ; i++){
        cord[i].x = center[i] - r; 
        cord[i].y = center[i] + r;

    }
}

int 
const HyperSphere::getDimensionDomain() 
{
    return dimensions;
}
        
double
const HyperSphere::getVolume() 
{
    return (std::pow(r,dimensions) * std::pow(M_PI, dimensions/2.0))/ std::tgamma((dimensions/2.0)+1.0);
} 

double
HyperSphere::generateRandomPoint()
{
    sum = 0; 
    point.reserve(dimensions);
    point.resize(dimensions);
        
    //this is to generate a random number (inside the hypercube)
        for(int j = 0; j < dimensions; j++){
            std::uniform_real_distribution<double> distribution(cord[j].x, cord[j].y);
            point[j] = distribution(re);
            sum += (point[j]-center[j])*(point[j]-center[j]);
        }
    if(sum > r*r){ 
        return -1;
    } 
    return sum;
}

double 
HyperSphere::getRadius()
{
    return r; 
}

std::vector<double> 
const HyperSphere::getPoint()
{
    return point;
}

std::string 
const HyperSphere::getFunction()
{
    return function;
}


