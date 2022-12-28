//Author: Twee Shackelford; 
//Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
//Lab: 6
//Purpose: distances

#include <iostream>  // cout, cin, endl ...
#include <iomanip>  // setprecision ...
#include <limits>
#include <cmath>
using namespace std;

void get_value(double& x, double& y, const string &prompt="enter point"){
	cout<<prompt<<" (x): ";
	cin>>x;
	cout<<prompt<<" (y): ";
	cin>>y;
}

double get_value(const string &prompt="enter a number between: ",
			double min=numeric_limits<double>::min(), 
			double max=numeric_limits<double>::max(),
            const string &errmsg="  invalid, try again\n"){
	double value {};
	while (true) {
   		cout<<prompt<<min<<" and "<<max<<": ";
   		if (cin>>value and value>=min and value <=max){
    		return value;
    	}
    	else {
			cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
   			 if (errmsg!="") cout<<errmsg;
		}
	}
}

char get_value(const string &prompt="enter letter: ",
            const string &errmsg="  invalid, try again\n"){
	char value {};
	while (true) {
   		cout<<prompt;
   		if (cin>>value and isalpha(value))
    		return value;
    	else {
			cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
   			cout<<errmsg;
		}
	}
}

double dist(double x1, double y1, double x2, double y2) {
	double value = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
	return value;
}

double dist(double n1, double n2) {
	double value = abs(n1 - n2);
	return value;
}

int dist(char c1, char c2) {
	int value;
	if (toupper(c1)>=toupper(c2)){
 	 	value = toupper(c1)-toupper(c2);
 	} else {
  		value = toupper(c2)-toupper(c1);
  	}
  	return value;
}

void display(const string &message="distnace is ", double x1=0, double y1=0, double x2=0, double y2=0){
	double result = dist(x1, y1, x2, y2);	
	cout<<message<<x1<<","<<y1<<" and "<<x2<<","<<y2<<" = "<<result<<"\n\n";
}

void display(double n1=0, double n2=0, const string &message="distnace is "){
	int result = dist(n1, n2);
	cout<<message<<n1<<" and "<<n2<<" = "<<result<<"\n\n";
}

void display(const string &message="distnace is ", char c1='a', char c2='a'){
	int result = dist(c1, c2);
	cout<<message<<c1<<" and "<<c2<<" = "<<result<<"\n\n";
}

int main() {
	char c1, c2, option;
	double n1, n2, x1, x2, y1, y2;
	enum Options {letter='l', number='n', point='p', quit='q'};
	while (true){
		cout << "Options: l)etter; n)umber; p)oint; q)uit: ";
		cin >> option;
		switch (option) {
			case 'l': c1 = get_value("enter first letter (a to z): ", "  invalid, try again\n");
				c2 = get_value("enter second letter (a to z): ", "  invalid, try again\n");
				display("Distance between letters ", c1, c2);
				break;
			case 'n': n1 = get_value("enter first number (-100 to 100): ", -100, 100);
				n2 = get_value("enter second number (-200 to 200): ", -200, 200);
				display(n1, n2, "Units between ");
				break;
			case 'p': get_value(x1, y1, "enter first point");
				get_value(x2, y2, "enter second point");
				display("straight line distance between points (", x1, y1, x2, y2);
				break;
			case 'q': cout<<"good bye!";
				break;
		}
		if (option == 'q') break;
	}
}

/*
Options: l)etter; n)umber; p)oint; q)uit: l
enter first letter (a to z): a
enter second letter (a to z): +
  invalid, try again
enter second letter (a to z): q
Distance between letters a and q = 16

Options: l)etter; n)umber; p)oint; q)uit: l
enter first letter (a to z): z
enter second letter (a to z): u
Distance between letters z and u = 5

Options: l)etter; n)umber; p)oint; q)uit: n
enter first number (-100 to 100): -100 and 100: -200
  invalid, try again
enter first number (-100 to 100): -100 and 100: 52
enter second number (-200 to 200): -200 and 200: -73
Units between 52 and -73 = 125

Options: l)etter; n)umber; p)oint; q)uit: p
enter first point (x): -2
enter first point (y): 5
enter second point (x): -7
enter second point (y): 2
straight line distance between points (-2,5 and -7,2 = 5.83095

Options: l)etter; n)umber; p)oint; q)uit: q
good bye!
--------------------------------
Process exited after 31.89 seconds with return value 0
Press any key to continue . . .
*/
