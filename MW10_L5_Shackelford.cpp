//Author: Twee Shackelford; 
//Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
//Lab: 0 
//Purpose: 

#include <iostream>  // cout, cin, endl ...
#include <fstream>  // open, close, eof
#include <iomanip>  // setprecision ...
#include <string>  //
using namespace std;

int main() {
	const string inFilePeople="people.txt";
	ifstream inFile(inFilePeople);
	if (inFile) {
		int yearCount = 1900;
		cout << "PRAIRIEVILLE POPULATION GROWTH \n"
			 << "(each * represents 1000 people)\n";
		while (!inFile.eof()) {
			int num = 0;
			inFile >> num;
			if (inFile.eof()) break;
			cout << yearCount << " ";
			for (int pop = num/1000; pop != 0; pop--){
				cout << "*";
			}
			cout << "\n";
			yearCount+= 20;
		}
		inFile.close();
	} else {
		cout << "error, file: " << inFilePeople << "inaccessable or not found. \n";
	}
	return 0;
}

