//Author: Twee Shackelford; 
//Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
//Lab: 3
//Purpose: tutor 3rd graders on simple addition

#include <iostream>  
#include <iomanip>  
#include <string>  
#include <random>  
using namespace std;

int main() {
	srand(time(0));
	int number{1};
	int ans{};
	int a{};
	int b{};
	int correct{};
	int questions{};
	cout << "Welcome to your 3rd Grade math tutor program." << endl;
	cout << "Today we will cover simple addition problems." << endl;
	cout << "Type '-1' at any time to end." << endl;
	cout << "How many questions would you like to start with? " << endl;
	cin >> questions;
	for (int count = 1; count <= questions; count++) {
		while (number >= 0) {
			ans = rand() % 101;
			a = rand() % (ans+1);
			b = ans - a;
			cout << "What is " << a << " + " << b << " = ? " << endl;
			cin >> number;
			if (number == ans) {
				cout << "Good job!" << endl;
				correct += 1;
			}
			else if (number >= 0) {
				cout << "I'm sorry but the correct answer was " << ans << endl;
			}
			else
				break;
		}
	}
	if (questions > 0) {
		int wrong{questions - correct};
		double total{correct/static_cast<double>(questions)*100};
		cout << "You got #" << correct << " correct, and #" << wrong << "wrong, for a grade of " << total << "%" << endl;
	}
	else
		cout << "You did not select enough questions to have a result screen :(" << endl;
	cout << "Goodbye! See you again next time!";
}

/*
Welcome to your 3rd Grade math tutor program.
Today we will cover simple addition problems.
Type '-1' at any time to end.
How many questions would you like to start with?
7
What is 9 + 62 = ?
71
Good job!
What is 2 + 0 = ?
2
Good job!
What is 62 + 30 = ?
92
Good job!
What is 5 + 60 = ?
7
I'm sorry but the correct answer was 65
What is 51 + 3 = ?
-1
You got #3 correct, and #4wrong, for a grade of 42.8571%
Goodbye! See you again next time!
--------------------------------
Process exited after 29.89 seconds with return value 0
Press any key to continue . . .
*/

