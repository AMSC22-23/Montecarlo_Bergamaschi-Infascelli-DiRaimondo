#include <iostream>
#include <vector>

using namespace std;

class HyperSphere{
private:
    double r = 0.0;   //radius
    vector<double> centro;
    int dimensions = 0;



public:
    void setDimensions(int n){
         dimensions = n;
    }
    int getDimensions(){
        return dimensions;
    }

    //il centro va letto con un ciclo for
}
