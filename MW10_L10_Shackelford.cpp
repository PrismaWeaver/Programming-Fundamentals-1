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
using namespace std;

class Person {
	public:
	    string name;     // name of the person
	    Person *next;    // pointer to the next person in the list
};

// Helpful macros to make it easier to output name, address, and value of a variable
// You may use these, or write your own function that does something similar
#define show_addr_value(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<"  "     \
      <<"contents of "<<setw(width)<<left<<#var<<" is: "<<var<<endl;

#define show_addr(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<endl;

int main () {
	cout << "Output from Lab10 memory diagram on pointers:\n\n";
  
	float price = 0;
	float *p_price = &price;
	*p_price = 19.95;
	show_addr_value(price, 8);
	show_addr_value(p_price, 8);
	cout << "The contents of *p_price is: " << *p_price << "\n\n";
	
	double PI = 3.141592;
	double *p_PI = &PI;
	double PI_div_2 = *p_PI/2;
	show_addr_value(PI, 8);
	show_addr_value(PI_div_2, 8);
	show_addr_value(p_PI, 8);
	cout << "The contents of *p_PI is: " << *p_PI << "\n\n";
	
	int maxSize = 5028;
	int *p_size = &maxSize;
	show_addr_value(maxSize, 8);
	show_addr_value(p_size, 8);
	cout << "The contents of *p_size is: " << *p_size << "\n\n";
	
	int *p_amount = new int;
	show_addr_value(p_amount, 8);
	*p_amount = 1234;
	cout << "The contents of *p_amount is: " << *p_amount << endl;
	delete p_amount;
	cout << "After delete, the contents of p_amount is: " << p_amount << endl;
	p_amount = nullptr;
	cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << "\n\n";
	
	int *pArray = new int [3];
	pArray[0]=11, pArray[1]=22, pArray[2]=33;
	show_addr_value(pArray, 8);
	show_addr_value(pArray[0], 8);
	show_addr_value(pArray[1], 8);
	show_addr_value(pArray[2], 8);
	delete [] pArray;
	cout << "After delete [], the contents of pArray is: " << pArray << endl;
	pArray = nullptr;
	cout << "After reset to nullptr, the contents of pArray is: " << pArray << "\n\n";
	
	Person *emptyList = nullptr;
	show_addr_value(emptyList, 8);
	cout <<"\n";
	delete emptyList;
	
	cout << "static (uses: Person wizard):" << endl;
	Person wizard;
	show_addr(wizard, 8);
	wizard.name = "Gandalf";
	wizard.next = nullptr;
	show_addr_value(wizard.name, 8);
	show_addr_value(wizard.next, 8);
	
	//I couldn't get the linked list pointer to work afer reading the book,
	//countless stackoverflow threads, and hours of attempt after attempt 
	//so I'm just calling it quits here, feel free to take off points
  
  return 0;
} // end of main

/*
Output from Lab10 memory diagram on pointers:

address of price    is: &0x70fdfc  contents of price    is: 19.95
address of p_price  is: &0x70fdf0  contents of p_price  is: 0x70fdfc
The contents of *p_price is: 19.95

address of PI       is: &0x70fde8  contents of PI       is: 3.14159
address of PI_div_2 is: &0x70fdd8  contents of PI_div_2 is: 1.5708
address of p_PI     is: &0x70fde0  contents of p_PI     is: 0x70fde8
The contents of *p_PI is: 3.14159

address of maxSize  is: &0x70fdd4  contents of maxSize  is: 5028
address of p_size   is: &0x70fdc8  contents of p_size   is: 0x70fdd4
The contents of *p_size is: 5028

address of p_amount is: &0x70fdc0  contents of p_amount is: 0x891570
The contents of *p_amount is: 1234
After delete, the contents of p_amount is: 0x891570
After reset to nullptr, the contents of p_amount is: 0

address of pArray   is: &0x70fdb8  contents of pArray   is: 0x891570
address of pArray[0] is: &0x891570  contents of pArray[0] is: 11
address of pArray[1] is: &0x891574  contents of pArray[1] is: 22
address of pArray[2] is: &0x891578  contents of pArray[2] is: 33
After delete [], the contents of pArray is: 0x891570
After reset to nullptr, the contents of pArray is: 0

address of emptyList is: &0x70fdb0  contents of emptyList is: 0

static (uses: Person wizard):
address of wizard   is: &0x70fda0
address of wizard.name is: &0x70fda0  contents of wizard.name is: Gandalf
address of wizard.next is: &0x70fda8  contents of wizard.next is: 0

--------------------------------
Process exited after 0.6015 seconds with return value 0
Press any key to continue . . .
*/
