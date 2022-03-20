#include <iostream>
#include "./tools/wiener.h"
#include "./tools/sim.h"
#include "./tools/csvin.h"
#include "./tools/ito.h"
#include "./tools/options/vanilla.h"

using namespace std;

double str = 15;

double f(double x) {
    double result = x-str;
    if (result <0) result = 0;
    return result;}


int main () {
    double S0 = 550, vol = 0.25, r_free = 0.01, str = 500, matur = 0.504;
    long sims = 10000;
    double S = vanilla(vol, matur, str, r_free, S0, call);
    double S_sim = vanilla_simulate(vol, matur, str, r_free, S0, sims, call);

    cout<< "call value is: " << S << endl;
    cout<< "call value from sim is: " << S_sim << endl;

    // cout << "rand(): " << rand() << endl;
    // cout << "RAND_MAX:" << RAND_MAX << endl;
    // cout << "static_cast:" << static_cast<double>(RAND_MAX) << endl;
    // cout << "x: " << 2*rand()/static_cast<double>(RAND_MAX) - 1 << endl;



    // long size = 1000; 
    // double sum=0, sq_sum=0;
    // double * I = itoInt(f, 0, 1, size);
    // for (int i = 0; i < size; i++){
    //     sum += I[i];
    //     sq_sum += pow(I[i],2);
    // }
    // cout<< "mean " << sum/double(size) <<"\n";
    // cout<< "var" << sq_sum/double(size) - pow(sum/double(size),2) << "\n";
    //
    //long len = 10;
    //double mean[len], std[len], mix[len];
    //for(int i = 0; i < len; i++){
    //    mean[i] = i/(len^2);
    //    std[i] = i/sqrt(len);
    //    mix[i] = (i+1)/(len*(len+1)/2);
    //}

    //float* sample = wienerVector(len);
    //for(int i = 0; i < len; i++)
    //    cout << sample[i] << "\n";
    //cout << dot(mean,std, len) << "\n";
    //vector<vector<string>> content = readcsv("./test.csv");
    //for(int i=0;i<content.size();i++)
	//{
	//	for(int j=0;j<content[i].size();j++)
	//	{
	//		cout<<content[i][j]<<" ";
	//	}
	//	cout<<"\n";

	//}

    

    return 0;
}