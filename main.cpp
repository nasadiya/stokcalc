#include <iostream>
#include "./tools/wiener.h"
#include "./tools/sim.h"
#include "./tools/csvin.h"
#include "./tools/ito.h"

using namespace std;

double f(double x) {return x;}


int main () {
    long size = 1000; 
    double sum=0, sq_sum=0;
    double * I = itoInt(f, 0, 1, size);
    for (int i = 0; i < size; i++){
        sum += I[i];
        sq_sum += pow(I[i],2);
    }
    cout<< "mean " << sum/double(size) <<"\n";
    cout<< "var" << sq_sum/double(size) - pow(sum/double(size),2) << "\n";
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