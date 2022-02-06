#include <iostream>
#include "./tools/wiener.h"
#include "./tools/sim.h"

int main () {
    //
    long len = 10;
    double mean[len], std[len], mix[len];
    for(int i = 0; i < len; i++){
        mean[i] = i/(len^2);
        std[i] = i/sqrt(len);
        mix[i] = (i+1)/(len*(len+1)/2);
    }

    double* sample = rNormVS(mean, std, len);
    for(int i = 0; i < len; i++)
        cout << sample[i] << "\n";
    //cout << dot(mean,std, len) << "\n";
    return 0;
}