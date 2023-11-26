#include <iostream>
#include <cmath>
#include <random>

using namespace std;
/*
class MontecarloIntegration{
private:
public:
     //constructor of the class
    MontecarloIntegration() = default;

    //creating all the samples

    //create the seed using random device
    std::random_device r;
    //create a random engine using the seed
    std::default_random_engine eng{r()};
    //then introduce the distribution, which is necessary when using engines
    //in this case, we're going to move inside the interval [0,1]
    std::uniform_real_distribution<double> dis{(0,1)};
};
*/

class MontecarloIntegration{
private:
    //this engine will be at least as good as the Mersenne Twister algorithm
    std::default_random_engine re;
    std::uniform_real_distribution<double> distribution;
    double integral = 0.0;

public:
    //constructor of the class
    MontecarloIntegration() : re(std::random_device{}()),distribution(0,1) {};

    //this function sets the seed
    void setSeed(unsigned);

    double integrate(int);
    
    double getIntegral(){
        return integral;
    }
};


/*
//another way of initializing
MontecarloIntegration::MontecarloIntegration() {
    //initialization of the generator (engine)
    gen = std::default_random_engine(std::random_device{}());
    //initialization of the distribution
    distribution = std::uniform_real_distribution<double>(0, 1);
}
*/
void MontecarloIntegration::setSeed(unsigned seed) {
    re.seed(seed);
}


double MontecarloIntegration::integrate(int samples){

    // compute the volume of the geometric form
    double volume = 0.0; //gli passo il volume della forma geometrica

    //conviene fare una classe astratta per una generica forma geometrica? oppure if else
    //the number of samples should be taken from the command line (?)
    for(int i=0; i<samples; i++){
        //
    }

    return 0; 
}