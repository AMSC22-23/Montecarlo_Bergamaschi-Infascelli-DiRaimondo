#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

namespace Domain {
class Domain {
    private : 
    int nDimension; 

    public : 

    Domain() = default; 

    Domain(int nDim){
        nDimension = nDim; 
    };

    virtual int getDimensionDomain() = 0; 

    virtual double getVolume() = 0; 
};
}
