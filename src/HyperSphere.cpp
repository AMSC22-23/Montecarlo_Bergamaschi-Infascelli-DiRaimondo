#include "HyperSphere.hpp"

//constructor of the HyperSphere
HyperSphere::HyperSphere(const string inputFile)
{
    ifstream input(inputFile);

    if (!input.is_open()) {
        cout << "Error opening input file: " << inputFile << endl;
        exit(-1);
    }

    input >> dimensions; 
    input >> r; 

    if(r <= 0.0){
        cout << "The value of the radius is not valid " << endl;
        cout << "The radius is:" << r << endl;
        exit(-1);
    }
        
    if(dimensions <= 0){
        cout << "The value of the dimension is not valid" << endl;
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

    #pragma omp parallel for num_threads(dimensions) shared(r,cord)
    for(int i=0; i < dimensions ; i++){
        //chiedere giovedì se parallelizzare anche queste due
        cord[i].x = center[i] - r; 
        cord[i].y = center[i] + r;

        //da togliere
    //    #pragma omp critical
   //     cout << omp_get_thread_num() << " " << i << " " << cord[i].x << " " <<cord[i].y << endl;
    }
    #pragma omp barrier
}

int 
HyperSphere::getDimensionDomain() 
{
    return dimensions;
}
        
double
HyperSphere::getVolume() 
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

    //bisogna rendere tutto thread safe perché altrimenti c'è il rischio che più thread creino gli stessi punti
        for(int j = 0; j < dimensions; j++){
            uniform_real_distribution<double> distribution(cord[j].x, cord[j].y);
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

vector<double> 
HyperSphere::getPoint()
{
    return point;
}

string 
HyperSphere::getFunction()
{
    return function;
}


