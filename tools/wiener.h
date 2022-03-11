
#ifndef WIENER_H
#define WIENER_H

#include <random>
using namespace std;

// single dW sample
double wienerIncrement(double interval){
    double multiplier = sqrt(interval);
    random_device r;
    mt19937 gen(r());
    normal_distribution<> N{0,1};
    return N(gen) * multiplier;
}

// single W sample
double wienerSample(double sims = 100){
    double sample = 0, increment = 1/sims;
    for(int n_sims = 0; n_sims < sims; n_sims++) 
        sample += wienerIncrement(increment);
    return sample;
}

// vector of dW samples
double* wienerIncrementSample(long size, double interval = 1/1000){
    double* sample;
    sample = new double[size];
    for(int n_sample = 0; n_sample < size; n_sample++)
        sample[n_sample] = wienerIncrement(interval);
    return sample;
}

// matrix of dW samples with each row representing 
double** wienerIncrementMatrix(long rows, long cols, double interval = 1/1000){
    double** sample;
    sample = new double*[rows];
    for(int n_row = 0; n_row < rows; n_row++)
        sample[n_row] = wienerIncrementSample(cols, interval);
    return sample;
}

// vector of W samples
double* wienerVector(long size, double sims = 100){
    double* sample;
    sample = new double[size];
    for(int n_sample = 0; n_sample < size; n_sample++)
    sample[n_sample] = wienerSample(sims);
    return sample;
}

#endif
