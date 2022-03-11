//#include <iostream>
#include "./wiener.h"
#include "./sim.h"
using namespace std;



// trapezoid method for integrals (limit a->b)

double trapezoid(double (*f)(double), double a, double b, double granularity){
    long size = int(granularity);
    double dF = (b-a)/granularity;
    double* dW = wienerIncrementSample(int(granularity), dF);
    double integral = 0, x_i = a, x_i1 = a + dW[0];

    for (int i = 0; i < size; i++){
        integral += 0.5 * dW[i] * (f(x_i) + f(x_i1));
        x_i = x_i1;
        x_i1 += dW[i+1];
    }

    return integral;
}

// simple ito integral for a function f(W)
// I = Int(f(W) dW; lim a -> b)
// As the integral is again a random variable, the output is a distribution
double* itoInt(double (*f)(double), double a, double b, long sample = 1000, double granularity = 1000){
    double* I;
    I = new double[sample];

    for(int i = 0; i < sample; i++){

        I[i] = trapezoid(f, a, b, granularity);
    }
    return I;
}