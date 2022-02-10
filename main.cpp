#include <iostream>
#include "./tools/wiener.h"
#include "./tools/sim.h"
#include "./tools/csvin.h"

using namespace std;

int main () {
    //
    long len = 10;
    double mean[len], std[len], mix[len];
    for(int i = 0; i < len; i++){
        mean[i] = i/(len^2);
        std[i] = i/sqrt(len);
        mix[i] = (i+1)/(len*(len+1)/2);
    }

    //float* sample = wienerVector(len);
    //for(int i = 0; i < len; i++)
    //    cout << sample[i] << "\n";
    //cout << dot(mean,std, len) << "\n";
    vector<vector<string>> content = readcsv("./test.csv");
    for(int i=0;i<content.size();i++)
	{
		for(int j=0;j<content[i].size();j++)
		{
			cout<<content[i][j]<<" ";
		}
		cout<<"\n";
	}

    return 0;
}