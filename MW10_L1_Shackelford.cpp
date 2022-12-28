//Author: Twee Shackelford; 
//Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
//Lab: 1 
//Purpose: This program calculates BMI, check, etc.

#include <iostream>
using namespace std;

int main() {
	cout<<"This program assists with dining out.\n\n";
	while (true) {
      cout<<"Options (enter one letter): a)dvice b)mi c)heck q)uit: ";
      char option=' ';
      cin >> option;
      if (option=='a') {
          // provide advice.
          cout<<"  Concentrate on what you crave and order a mindful amount \n\n";
      }
      else if (option=='b') {
      	  // compute and display the BMI
      	int weight{0};
      	cout<<"  Please enter your weight in pounds (lb):  ";
      	cin>> weight;
      	cout<<"  The weight you entered was: "<<weight<<endl;
        
        int height{0};
        cout<<"  Please enter your height in inches (in):  ";
        cin>> height;
        cout<<"  The height you entered was: "<<height<<endl;
        
        static_cast<double>(height);
        cout<<"  BMI = "<<weight/(static_cast<double>(height)*height)*703<<"\n\n"<<endl;
        
      }
      else if (option=='c') {
          // compute and display check amount
          double cost{0};
		  cout<<"  What is the cost of the food?: $";
          cin>> cost;
          double percent{0};
          cout<<"  What percentage tip would you like to leave? (example: 20): ";
		  cin>> percent;
		  const double TAX_RATE = 0.0825;
		  //tip based on food cost + tax
		  double tip{cost*(TAX_RATE+1)*(percent/100)};
		  cout<<"  You should leave a tip of: $"<<tip<<"\n"<<endl;
		  cout<<"  Your total bill is: $"<<cost*(TAX_RATE+1)+tip<<"\n\n"<<endl;
          
      }
      else if (option=='q')
          break;
      else
          // invalid option entered, display an error message
          cout<<"  That was not an option listed please try again. \n\n"<<endl;
          ;
  }
}

/* Test output:
This program assists with dining out.

Options (enter one letter): a)dvice b)mi c)heck q)uit: a
  Concentrate on what you crave and order a mindful amount

Options (enter one letter): a)dvice b)mi c)heck q)uit: b
  Please enter your weight in pounds (lb):  185
  The weight you entered was: 185
  Please enter your height in inches (in):  67
  The height you entered was: 67
  BMI = 28.9719


Options (enter one letter): a)dvice b)mi c)heck q)uit: c
  What is the cost of the food?: $20
  What percentage tip would you like to leave? (example: 20): 20
  You should leave a tip of: $4.33

  Your total bill is: $25.98


Options (enter one letter): a)dvice b)mi c)heck q)uit: r
  That was not an option listed please try again.


Options (enter one letter): a)dvice b)mi c)heck q)uit: q

--------------------------------
Process exited after 24.73 seconds with return value 0
Press any key to continue . . .
*/
