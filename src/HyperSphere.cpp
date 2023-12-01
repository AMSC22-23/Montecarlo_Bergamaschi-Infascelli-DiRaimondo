#include <iostream>
#include <vector>
#include <string> 
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <random>
#include "Domain.hpp" 

using namespace std;

struct Range {
    double x,y; 
}; 

class HyperSphere : public Domain {
private:
    double r = 0.0;   //radius
    vector<double> center;
    int dimensions = 0, numIn=0, numTot=0;
    double x,sum; 
    double rv = 0.0;
    mt19937 re{random_device{}()};
    vector<Range> cord;
    vector<double> point;


public:
    //constructor of the HyperSphere
    HyperSphere(const string inputFile){
        ifstream input(inputFile);
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
        for(int i = 0 ; i < dimensions; i++){
            input >> x; 
            center.emplace_back(x);
        }
            /*
            for(int i = 0 ; i < dimensions; i++){
                cout << center[i] << endl;
            }
            */
            //it's necessary to reserve enough space for the vector
        cord.reserve(dimensions);
        cord.resize(dimensions);
        
        for(int i=0; i < dimensions ; i++){
            cord[i].x = center[i] - r; 
            cord[i].y = center[i] + r;
        }
        
        }

        int getDimensionDomain() {
            return dimensions;
        }
        
        double getVolume() {
            return (std::pow(r,dimensions) * std::pow(M_PI, dimensions/2.0)) / std::tgamma((dimensions/2.0)+1.0);
        }

       double generateRandomPoint(){
            sum = 0; 
            point.reserve(dimensions);
            point.resize(dimensions);
        
            //this is to generate a random number (inside the hypercube)

            for(int j = 0; j < dimensions; j++){
                uniform_real_distribution<double> distribution(cord[j].x, cord[j].y);
                point[j] = distribution(re);
                std::cout << "The "<< j << "th coordinate of the number is " << point[j] << endl;
                sum += (point[j]-center[j])*(point[j]-center[j]);
            }
            if(sum > r*r){ 
                //metto point a null oppure elimino tutti i suoi elementiz
                return -1;
            } 
            return sum;
        }

        double getRadius(){
            return r; 
        }
        vector<double> getPoint(){
            return point;
        }

    };

