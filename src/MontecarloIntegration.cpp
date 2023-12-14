#include "MontecarloIntegration.hpp"

using namespace std;

double MontecarloIntegration::getIntegral()
{
    return integral;
}
//

double MontecarloIntegration::integrate(unique_ptr<Domain> &d, int samples)
{
    
    double sum =0 ; 
    vector<double> point; 
    double volume = 0.0; //gli passo il volume della forma geometrica

    string start = "x";
    string num;

    mu::Parser pf;
    pf.SetExpr(d->getFunction());

    double somma = 0;

    while(d->generateRandomPoint() == -1);
    point = d->getPoint();
    for(int h = 1; h <= d->getDimensionDomain(); h++) {
        start = "x";
        num = to_string(h);
        start = start + num;
        pf.DefineVar(start,&point[h-1]);
    }  
    somma+= pf.Eval();
    //se non sono entrata nell'if significa che il punto non sta nel dominio
    //anziché moltiplicare qui per il volume, moltiplico solo una volta nel main
    return somma; 
}