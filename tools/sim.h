// Normal mixture sampling

#ifndef SIM_H
#define SIM_H

#include <random>

using namespace std;


// function to compute dot product of two double vectors
double dot(double* a, double* b, long size){

    double dotproduct = 0;
    for (long i = 0; i < size; i++)
        dotproduct += a[i] * b[i];
    return dotproduct;
}

// single standard normal sample 
double rNorm(){
    random_device r;
    seed_seq seed{r()};
    mt19937 eng(seed);
    normal_distribution<> N{0,1};
    return N(eng);
}

// N sample of standard normal
double* rNormV(long sims = 1){
    double* sample;
    sample = new double[sims];
    for(long n_sample = 0; n_sample < sims; n_sample++)
        sample[n_sample] = rNorm();
    return sample;
}

// N sample of normal with mean m and standard deviation s
double* rNormVS(double* mean, double* std, long sims = 1){

    double *sample, *standard;
    sample = new double[sims];
    standard = rNormV(sims);

    for(long n_sample = 0; n_sample < sims; n_sample++)
        sample[n_sample] = mean[n_sample] + std[n_sample] * standard[n_sample];
    return sample;
}

// Sample from a p-mixture distribution of normals with 
// given mean, standard deviation, and mixture probability vectors.
double* rMixNormV(double* mean, double* std, double* mix, long size, long sims = 1){

    double* sample;
    sample = new double[sims];

    long p = sizeof(*mix);

    for (int i = 0; i < sims; i++)
        sample[i] = dot(mix, rNormVS(mean,std,sims), size);
    
    return sample;
}

#endif