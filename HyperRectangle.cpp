#include <iostream>
#include <vector>
#include <string> 
#include <cmath>
#include <cstdlib>
#include "Domain.cpp"
#include  <fstream>

using namespace std; 

namespace Domain {
    struct Coordinate {
        double x,y; 
    }; 

    class HyperRectangle : public Domain{

        private:
        int dimensions; 
        vector<Coordinate> cord; 

        public:
        HyperRectangle(string inputFile){
            ifstream input(inputFile);
            input >> dimensions; 
            for(int i=0; i < dimensions/2 ; i++){
                input >> cord[i].x; 
                input >> cord[i].y; 
            }
        }

        int getDimensionDomain() override{
            return dimensions;
        }
        
        double getVolume() override {
            double totVol = 1; 
            for(int i=0; i < dimensions/2; i++){
                totVol = 1; 
            }
        }
    };
}