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
            if (!input.is_open()) {
                cout << "Error opening input file: " << inputFile << endl;
                exit(-1);
            }

            input >> dimensions; 
                
            if(dimensions <= 0){
                cout << "The value of the dimension is not valid" << endl;
                exit(-1);
            }
            for(int i=0; i < dimensions ; i++){
                input >> cord[i].x; 
                input >> cord[i].y; 
            }
        }

        int getDimensionDomain() {
            return dimensions;
        }
        
        double getVolume()  {
            double totVol = 1; 
            for(int i=0; i < dimensions; i++){
                totVol = totVol * abs(cord[i].x-cord[i].y); 
            }
            return 0;
        }
        double generateRandomPoint(){     
            
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
        vector<double> getPoint(){
            return point;
        }
        string getFunction(){
            return function;
        }
    };
