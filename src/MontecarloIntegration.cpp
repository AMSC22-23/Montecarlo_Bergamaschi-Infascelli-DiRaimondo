#include "MontecarloIntegration.hpp"


double const MontecarloIntegration::getIntegral()
{
    return integral;
}

double MontecarloIntegration::integrate(std::unique_ptr<Domain> &d, int samples)
{
    
    double sum =0 ; 
    std::vector<double> point; 
    double volume = 0.0; //gli passo il volume della forma geometrica

    std::string start = "x";
    std::string num;

    mu::Parser pf;
    pf.SetExpr(d->getFunction());

    double somma = 0;

    while(d->generateRandomPoint() == -1);
    point = d->getPoint();
    for(int h = 1; h <= d->getDimensionDomain(); h++) {
        start = "x";
        num = std::to_string(h);
        start = start + num;
        pf.DefineVar(start,&point[h-1]);
    }  
    somma+= pf.Eval();
    //se non sono entrata nell'if significa che il punto non sta nel dominio
    //anziché moltiplicare qui per il volume, moltiplico solo una volta nel main
    return somma; 
}