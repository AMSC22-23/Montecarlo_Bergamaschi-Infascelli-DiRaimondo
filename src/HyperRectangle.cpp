#include <iostream>
#include <vector>
#include <string> 
#include <cmath>
#include <cstdlib>
#include "Domain.hpp"
#include  <fstream>

using namespace std; 
    struct Edges {
        double x,y; 
    }; 

    class HyperRectangle : public Domain{

        private:
        int dimensions; 
        vector<Edges> cord; 
        mt19937 re{random_device{}()};
        vector<double> point;
        string function;

        public:
        //da modificare

        HyperRectangle(string inputFile){
            ifstream input(inputFile);
            input >> dimensions; 
            cout << "dimension of hr: " << dimensions << endl;
            for(int i=0; i < dimensions/2 ; i++){
                input >> cord[i].x; 
                input >> cord[i].y; 
            }
        }

        int getDimensionDomain() {
            return dimensions;
        }
        
        double getVolume()  {
            double totVol = 1; 
            for(int i=0; i < dimensions/2; i++){
                totVol = 1; 
            }
            return 0;
        }
        double generateRandomPoint(){
            //
            return 0;
        }
        vector<double> getPoint(){
            return point;
        }
        string getFunction(){
            return function;
        }
    };
