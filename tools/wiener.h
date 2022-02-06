#include <iostream>
#include <random>
using namespace std;

// single dW sample
float wienerIncrement(float interval){
    float multiplier = sqrt(interval);
    random_device r;
    mt19937 gen(r());
    normal_distribution<> N{0,1};
    return N(gen) * multiplier;
}

// single W sample
float wienerSample(float sims = 100){
    float sample = 0, increment = 1/sims;
    for(int n_sims = 0; n_sims < sims; n_sims++) 
        sample += wienerIncrement(increment);
    return sample;
}

// vector of dW samples
float* wienerIncrementSample(long size, float sims = 100){
    float* sample;
    sample = new float[size];
    for(int n_sample = 0; n_sample < size; n_sample++)
        sample[n_sample] = wienerSample(sims);
    return sample;
}

// vector of W samples
float* wienerVector(long size, float sims = 100){
    float* sample;
    sample = new float[size];
    for(int n_sample = 0; n_sample < size; n_sample++)
    sample[n_sample] = wienerSample(sims);
    return sample;
}