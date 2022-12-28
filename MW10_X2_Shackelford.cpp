/*
  Name: Jade Shackelford
  COSC 1337 Spring 2020 MW10
  Exam 2, Programming portion
  When complete: Change course designator in filename from DDHH to MW10
                 Change "Lastname" to your lastname.
  Upload file: MW10_X2_Shackelford.cpp to BlackBoard Assignment link.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

template <typename T>
T getinput(const string &prompt="input: ",
          const string &errmsg="error!",
          T my_default = T{}) {
	while (true) {
  		cout<<prompt;
  		T input{};
  		if (cin>>input) {
  			return input;
    	} else {
  			cout<<errmsg<<endl;
  			cin.clear();
  			cin.ignore(4095, '\n');
    	}
    }	
}

/*Step 1. (5 points)
In class Purse, write two Purse constructors:
default: set all coin counts to zero; do not allow the coin counts to be uninitialed.
2nd:    set all coin counts to non-negative initial values; use parameters for:
        quarter, dime, nickel, penny. To save time, you can use parameters: q, d, n, p.
        IMPORTANT: prohibit negative values - if negative coin value given, use 0 instead.
Tip: you can combine both of these into one constructor using default parameters*/
class Purse {
	private:
		int q, d, n, p;
/*Step 6. (5 points)
To avoid redundant code and insure proper validation, modify constructor(s)
as needed to call set() instead of having redundant checking code.*/
	public:
  		Purse() {
			set(0, 0, 0, 0);
		}
/*Step 5. (5 points)
In class Purse, implement a mutator/setter called set() which sets the
coin counts of all coins. Pre-validate any new coin counts; do not allow any
coin count to be less than zero. If the ANY of the coin counts are invalid
(negative), do not modify ANY coin counts. If the set() succeeds, return true;
if the set() fails, return false.*/
		bool set (int quart, int dime, int nick, int pen) {
			if (quart >= 0 && dime >= 0 && nick >= 0 && pen >= 0) {
				q=quart;
				d=dime;
				n=nick;
				p=pen;
				return true;
			}
			else return false;
		}
/*Step 9. (5 points)
In class Purse, write a modify() method that modifies coin counts
using a positive (increment), negative (decrement) or zero (keep the same)
value. For example:
    purse.modify(0, 0, 2, -3) This will: keep quarters, dimes the same;
    increase nickels by 2, and decrease pennies by 3.
IMPORTANT! Do not allow coin counts to become less than zero! If ANY coin will
become negative, don't make any changes.
If modify() succeeds, return true; if modify() fails, return false*/
    	bool modify(int quart, int dime, int nick, int pen) {
    		if ((q+quart)>=0 && (d+dime)>=0 && (n+nick)>=0 && (p+pen)>=0) {
    			q+=quart;
    			d+=dime;
    			n+=nick;
    			p+=pen;
    			return true;
			}
			else return false;
		}
/*Step 7. (5 points)
In class Purse, write a show() method that outputs the number of each
.coin in the purse in one string, like this: "(q=4 d=3 n=2 p=1)" (no endl or "\n")
Another option is to return a string. The caller can cout the string. This way,
class Purse is no longer dependent upon iostream.*/
		void show() {
			cout << "q=" << q << " d=" << d << " n=" << n << " p=" << p;
		}
/*Step 3. (5 points)
In class Purse, write the definition for a new public member function: total_value.
total_value returns the total value of all quarters, dimes, nickels and pennies
in a Purse object. For example: a purse with 4 quarters, 3 dimes,
2 nickels and 1 penny has a total value of (4*25)+(3*10)+(2*5)+(1*1)=141 (cents)
This is a getter / accessor, and should be marked const.*/
		int total_value() {
			float total = ((q*25)+(d*10)+(n*5)+(p))/100;
			return total;
		}
};
		
int main() {
/*Step 2. (5 points)
In main, in one statement, declare a new Purse object called purse and initialize
purse with: 4 quarters, 3 dimes, 2 nickels, 1 penny*/
	Purse purse;
	bool success = purse.set(4, 3, 2, 1);
/*Step 4. (5 points)
In main, write code to call the total_value method on the purse object.
Display the returned value, which is the total value of the coins in purse.
Format the output so it displays in dollars and cents. Example: $1.41
Hint: setprecision, fixed*/
	float total = purse.total_value();
	cout << "Total value in purse: $" << setprecision(2) << total << endl;
/*Step 8. (5 points)
In main, call set to change the values in purse to: 8 quarters, 7 dimes, 6 nickels, 5 pennies.
In main, call show to display the contents of purse (number of each coin).*/
	success = purse.set(8, 7, 6, 5);
	purse.show();
/*Step 10 (10 points)
In main, write a menu driven loop that allows the user the add or remove coins from purse.
In a loop, display the total value, coins and options. Use s to stop (q is for quarter). For example:
    $3.05 (q=8 d=7 n=6 p=5) Modify p)enny n)ickel d)ime q)uarter s)top: p -3
    $3.02 (q=8 d=7 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: n 0
    $3.02 (q=8 d=7 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: d 2
    $3.12 (q=8 d=9 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: q -4
    $2.12 (q=4 d=9 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: s
Use the provided get_value function to get the option letter and the count.
Your user interface should look similar to example above.
Important: Use if (cin >> x) checking so invalid numeric input does not cause crash or infinite loop.
    You can use get_input code developed earlier to provide one function for getting input. Required!*/
    bool running{true};
    char menu{};
    int pen, nick, dime, quart;
	while(running){
		success = false;
		total = purse.total_value();
		cout << "$" << setprecision(2) << total << " ";
		purse.show();
		menu = getinput<char>("Modify p)enny n)ickel d)ime q)uarter s)top:");
		switch (tolower(menu)){
			case 'p':{
				while (!success){
					pen = getinput<int>();
					success = purse.modify(0, 0, 0, pen);
					if (!success) cout << "Please enter a value that won't set the amount to less than 0\n";
				}				
				break;
			}
			case 'n':{
				while (!success){
					nick = getinput<int>();
					success = purse.modify(0, 0, nick, 0);
					if (!success) cout << "Please enter a value that won't set the amount to less than 0\n";
				}
				break;
			}
			case 'd':{
				while (!success){
					dime = getinput<int>();
					success = purse.modify(0, dime, 0, 0);
					if (!success) cout << "Please enter a value that won't set the amount to less than 0\n";
				}
				break;
			}
			case 'q':{
				while (!success){
					quart = getinput<int>();
					success = purse.modify(quart, 0, 0, 0);
					if (!success) cout << "Please enter a value that won't set the amount to less than 0\n";
				}
				break;
			}
			case 's':{
				running = false;
				break;
			}
			default:
				cout << "Please enter a valid answer\n\n";
		}
	}
}

/*  Step 11) Paste test output here (do this after step 12 if doing extra credit)
Total value in purse: $1
q=8 d=7 n=6 p=5$3 q=8 d=7 n=6 p=5Modify p)enny n)ickel d)ime q)uarter s)top:p
input: 4
$3 q=8 d=7 n=6 p=9Modify p)enny n)ickel d)ime q)uarter s)top:n
input: 2
$3 q=8 d=7 n=8 p=9Modify p)enny n)ickel d)ime q)uarter s)top:d
input: -10
Please enter a value that won't set the amount to less than 0
input: 3
$3 q=8 d=10 n=8 p=9Modify p)enny n)ickel d)ime q)uarter s)top:s

--------------------------------
Process exited after 26.95 seconds with return value 0
Press any key to continue . . .
*/

