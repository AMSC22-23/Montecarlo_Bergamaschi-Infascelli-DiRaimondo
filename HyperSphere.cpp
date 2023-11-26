#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class HyperSphere{
private:
    double r = 0.0;   //radius
    vector<double> center;
    int dimensions = 0;


public:
    HyperSphere(){
        //constructor
        //set the number of dimensions
        //...

        //set the radius
        //...

        //check if the value of r is valid
        if(r <= 0.0){
            cout << "The value of the radius is not valid " << endl;
            exit(-1);
        }
        //set the center
    }
    void setDimensions(int n){
         dimensions = n;
    }
    int getDimensions(){
        return dimensions;
    }
    
    double getVolume() const{
        return (std::pow(r,dimensions) * std::pow(M_PI, dimensions/2.0)) / std::tgamma((dimensions/2.0)+1.0);
    }

};