//#include <iostream>
#include "./wiener.h"
#include "./sim.h"
using namespace std;



// trapezoid method for integrals (limit a->b)

double trapezoid(double (*f)(double), double a, double b, long sample_size = 1000){
    double scalar = sqrt((b-a)/1000);
    double* dW = wienerIncrementSample(sample_size);
    double integral = 0, x_i = a, x_i1 = a + dW[0]*scalar;

    for (int i = 0; i < sample_size; i++){
        integral += 0.5 * dW[i] * scalar * (f(x_i) + f(x_i1));
        x_i = x_i1;
        x_i1 += dW[i+1] * scalar;
    }

    return integral;
}

// simple ito integral for a function f(W)
// I = Int(f(W) dW; lim a -> b)
// As the integral is again a random variable, the output is a distribution
double* itoInt(double (*f)(double), double a, double b, long sample = 1000){
    double* I;
    I = new double[sample];

    for(int i = 0; i < sample; i++){

        I[i] = trapezoid(f, a, b);
    }
    return I;
}