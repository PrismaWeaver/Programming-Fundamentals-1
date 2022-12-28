/*
  Author:		   Jade Shackelford
  Assignment:      Lab 10
  Topic:           memory diagram with stack, heap structures
  File Name:	   MW10_L10_Shackelford
  Course/Section:  COSC 1337
  Due Date:        5/11/2020
  Instructor:      Thayer
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

template <typename T>
T getinput(const string &prompt="input: ", const string &errmsg="error!", T my_default = T{}) {
  while (true) {
  	cout<<prompt;	T input{};
  	if (cin>>input) return input;
  	cout<<errmsg<<endl;	cin.clear(); cin.ignore(4095, '\n');
  }
}

int linearSearch(const string array[], int size, string target) {
  for (int i = 0; i < size; ++i)
    if (array[i] == target) {
	return i;
	}
  return -1;
}

int date_copy = 0;
const static int YEAR = 2019;
const static int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const static string monthsInYear[12] = {"jan", "feb", "mar", "apr", "may", "jun", 
										"jul", "aug", "sep", "oct", "nov", "dec"};

class Day {
	private:
		int date;
	public:		
		Day (int day){
			if (day < 0){
				date = 0;
			}
			else if (day > 365) {
				while (day > 365){
					day -= 365;
				}
				date = day;
			}
			else {
				date = day;
			}
			date_copy=date;			
		}
		
		Day (string t_month, int day) {
			int month = linearSearch(monthsInYear, 11, t_month);
			if (month != -1) {
				if (day <= daysInMonth[month]) {
					date = 0;
					for (int monthNum = 0; monthNum < month; monthNum++){
						date += daysInMonth[monthNum];
					}
					date += day;
				}
				else {date = 0;}
			}
			else {date = 0;}
			date_copy=date;
		}
		
		Day& operator++() {
			if (date < 365) {
				date++;
			}
			else {date=1;}
			return *this;
		}
		Day operator++(int){
			if (date < 365) {
				Day temp = *this;
				++*this;
				return temp;
			}
			else {date=1;}
		}
		
		Day& operator--(){
			if (date > 1) {
				date--;
			}
			else {date=365;}
			return *this;
		}
		Day operator--(int){
			if (date > 1) {
				Day temp = *this;
				--*this;
				return temp;
			}
			else {date=365;}
		}
		
		void print() {
			if (date != 0) {
				int t_date = date, month = 0;
				for (month; t_date > daysInMonth[month]; month++) {
					t_date -= daysInMonth[month];
				}
				cout << monthsInYear[month] << " " << t_date << ", " << YEAR << endl;
			}
			else {
				cout << "error, date input incorrect. Check if day entered is within range."
					 << endl;
			}
		}
};

void test_op(Day temp) {
  cout<<"start at: "; temp.print(); cout<<endl;
  for (int i=0; i<5; ++i) {cout<<" "; (--temp).print();} cout<<endl;
  for (int i=0; i<5; ++i) {cout<<" "; (++temp).print();} cout<<endl;
  for (int i=0; i<5; ++i) {cout<<" "; (temp++).print();} cout<<endl;
  for (int i=0; i<5; ++i) {cout<<" "; (temp--).print();} cout<<endl;
  cout<<"end at: "; temp.print(); cout<<endl;
}

int main() {
	bool loop = true;
	while(loop){
		string month;
		char option;
		enum Options {d = 'd', m = 'm', o = 'o', q = 'q'};
		int input, count =0;
		cout << "d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: " << endl;
		cin >> option;
		switch (option) {
			case d: {
				while (true) {
					input = getinput<int>("enter day of year# (-9 to quit): ", "please enter valid number");
					if (input == -9){break;}
					Day dateInst(input);
					dateInst.print();
				}
				break;
			}
			case m: {
				while (true) {
					month = getinput<string>("enter month: ", "please enter a valid string");
					if (month == "-9") {break;}
					input = getinput<int>("enter day of year# (-9 to quit): ", "please enter valid number");
					if (input == -9){break;}
					Day dateInst(month, input);
					dateInst.print();
				}
				break;
			}
			case o: {
				Day dateInst(date_copy);
				test_op(dateInst);
				break;
			}
			case q: {
				loop = false;
				cout << "exit testing loop";
				break;
			}
			default:
				cout << "please enter a valid answer." << endl;
		}
	}	
  return 0;
} // end of main

/*
d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; q)uit:
d
enter day of year# (-9 to quit): 5
jan 5, 2019
enter day of year# (-9 to quit): 46
feb 15, 2019
enter day of year# (-9 to quit): 365
dec 31, 2019
enter day of year# (-9 to quit): 1000
sep 27, 2019
enter day of year# (-9 to quit): -9
d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; q)uit:
m
enter month: jan
enter day of year# (-9 to quit): 1
jan 1, 2019
enter month: mar
enter day of year# (-9 to quit): 30
mar 30, 2019
enter month: dec 45
enter day of year# (-9 to quit): error, date input incorrect. Check if day entered is within range.
enter month: stop
enter day of year# (-9 to quit): -9
d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; q)uit:
d
enter day of year# (-9 to quit): 85
mar 26, 2019
enter day of year# (-9 to quit): -9
d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; q)uit:
o
start at: mar 26, 2019

 mar 25, 2019
 mar 24, 2019
 mar 23, 2019
 mar 22, 2019
 mar 21, 2019

 mar 22, 2019
 mar 23, 2019
 mar 24, 2019
 mar 25, 2019
 mar 26, 2019

 mar 26, 2019
 mar 27, 2019
 mar 28, 2019
 mar 29, 2019
 mar 30, 2019

 mar 31, 2019
 mar 30, 2019
 mar 29, 2019
 mar 28, 2019
 mar 27, 2019

end at: mar 26, 2019

d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; q)uit:
d
enter day of year# (-9 to quit): 1
jan 1, 2019
enter day of year# (-9 to quit): -9
d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; q)uit:
o
start at: jan 1, 2019

 dec 31, 2019
 dec 30, 2019
 dec 29, 2019
 dec 28, 2019
 dec 27, 2019

 dec 28, 2019
 dec 29, 2019
 dec 30, 2019
 dec 31, 2019
 jan 1, 2019

 jan 1, 2019
 jan 2, 2019
 jan 3, 2019
 jan 4, 2019
 jan 5, 2019

 jan 6, 2019
 jan 5, 2019
 jan 4, 2019
 jan 3, 2019
 jan 2, 2019

end at: jan 1, 2019

d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; q)uit:
q
exit testing loop
--------------------------------
Process exited after 92.98 seconds with return value 0
Press any key to continue . . .
*/
