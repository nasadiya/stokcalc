//#include <iostream>
#include "./wiener.h"
using namespace std;

// simple ito integral for a function f(W)
// I = Int(f(W) dW)
double itoInt(double* f, int granularity = 1000){
    float* dW = wienerIncrementSample(granularity);
    double integral = 0;
    for(int i_sum = 0; i_sum < granularity; i_sum++);
    return 0;
}