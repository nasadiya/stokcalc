#include <iostream>
#include "./tools/wiener.h"

int main () {
    //
    int len = 10;
    float* sample = wienerVector(10);
    for(int i = 0; i < len; i++)
    cout << sample[i] << "\n";

    return 0;
}