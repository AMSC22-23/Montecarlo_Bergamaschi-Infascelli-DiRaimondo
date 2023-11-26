#include <iostream>
#include <vector>
#include <string> 
#include <cmath>
#include <cstdlib>
#include "Domain.cpp"
#include  <fstream>

using namespace std;
namespace Domain {
    class HyperSphere: public Domain {
    private:
        double r = 0.0;   //radius
        vector<double> center;
        int dimensions = 0;
        double x; 


    public:
        
        HyperSphere(string inputFile){
            
            ifstream input(inputFile);
            input >> dimensions; 
            input >> r; 

            if(r <= 0.0 || dimensions <= 0){
                cout << "The value of the radius/dimensions is not valid " << endl;
                exit(-1);
            }

            for(int i = 0 ; i < dimensions; i++){
                input >> x; 
                center.emplace_back(x);
            }
        }

        int getDimensionDomain() override{
            return dimensions;
        }
        
        double getVolume() override {
            return (std::pow(r,dimensions) * std::pow(M_PI, dimensions/2.0)) / std::tgamma((dimensions/2.0)+1.0);
        }

    };
}
