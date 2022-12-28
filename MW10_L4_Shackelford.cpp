//Author: Twee Shackelford; 
//Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
//Lab: 4
//Purpose: 

#include <iostream>  // cout, cin, endl ...
#include <iomanip>  // setprecision ...
#include <string>  //
using namespace std;

int main() {
	enum Choices { air = 'a', water = 'w', steel = 's', quit = 'q'};
	char choice;
	double dist;
	double result;
	bool check{1};
	cout << "This program calculates the time in seconds for sound to\n";
	cout << "travel through various materials across various distances\n";
	cout << "measured in feet.\n";
	cout << "Options are: (A)ir, (W)ater, or (S)teel\n\n";
	
	while (true) {
		cout << "please select an option (q to quit at anytime): ";
		cin >> choice;
		check = 1;
		switch (choice) {
			case air:  		while (check) {
								cout << "What's the distance? : ";
								cin >> dist;
								if (dist > 0){
									check = 0;	
								}
								else if (dist <= 0){
									cout << "Please enter a valid distance larger than 0.\n";
									check = 1;
								}
								else {
									cout << "Please enter a valid number larger than 0 for the distance.\n";
									check = 1;
								}
							}
							result = dist / 1100;
							cout << setprecision(4) << "It would take sound " << result << " seconds to travel through " << fixed << dist << " feet of air.\n\n";
							break;
			case water:		while (check) {
								cout << "What's the distance? : ";
								cin >> dist;
								if (dist > 0){
									check = 0;	
								}
								else if (dist <= 0){
									cout << "Please enter a valid distance larger than 0.\n";
									check = 1;
								}
								else {
									cout << "Please enter a valid number larger than 0 for the distance.\n";
									check = 1;
								}
							}
							result = dist / 4900;
							cout << setprecision(4) << "It would take sound " << result << " seconds to travel through " << fixed << dist << " feet of water.\n\n";
							break;
			case steel:		while (check) {
								cout << "What's the distance? : ";
								cin >> dist;
								if (dist > 0){
									check = 0;	
								}
								else if (dist <= 0){
									cout << "Please enter a valid distance larger than 0.\n";
									check = 1;
								}
								else {
									cout << "Please enter a valid number larger than 0 for the distance.\n";
									check = 1;
								}
							}
							result = dist / 16400;
							cout << setprecision(4) << "It would take sound " << result << " seconds to travel through " << fixed << dist << " feet of steel.\n\n";
							break;
			case quit:		cout<<"Good bye!\n"; 
							break;
			default:		cout << "The option you entered is invalid, please try again.";
							break;
		}
		if (choice == 'q') break;
	}
}

/*
This program calculates the time in seconds for sound to
travel through various materials across various distances
measured in feet.
Options are: (A)ir, (W)ater, or (S)teel

please select an option (q to quit at anytime): a
What's the distance? : 5
It would take sound 0.004545 seconds to travel through 5.0000 feet of air.

please select an option (q to quit at anytime): w
What's the distance? : 900
It would take sound 0.1837 seconds to travel through 900.0000 feet of water.

please select an option (q to quit at anytime): f
The option you entered is invalid, please try again.please select an option (q t
o quit at anytime): s
What's the distance? : 959595
It would take sound 58.5119 seconds to travel through 959595.0000 feet of steel.


please select an option (q to quit at anytime): q
Good bye!

--------------------------------
Process exited after 29.32 seconds with return value 0
Press any key to continue . . .
*/
