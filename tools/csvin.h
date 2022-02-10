// function to input a file of the format
//   'Var1'   'Var2'     'Var3'      ...     'VarP'
//  value11   value12    value13     ...     value1P
//    ...      ...         ...       ...       ...
//  valueN1   valueN2    valueN3     ...     valueNP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<string>> readcsv(string fname){

    vector<vector<string>> content;
    vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else cout<<"Could not open the file\n";
    
    return content;
} 