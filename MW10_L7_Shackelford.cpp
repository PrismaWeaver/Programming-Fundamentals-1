/*
  Programmer:
  Assignment:           Lab 7
  Topic:                Implement and test class Item
  File Name:            DDHH_L7_Lastname.cpp
  Course/Section:       COSC 1337; Section DDHH
  Due Date:             See syllabus or blackboard
  Instructor:           Thayer
*/

// Compiler directives
#include <iostream> // for cin, cout, endl
#include <iomanip>
#include <string>
using namespace std;

template <typename T>
T get_input(string prompt="input: ", T my_default = T{}) {
  while (true) {
  	cout<<prompt;	T input{};
  	if (cin>>input){
		return input;
	}
	else {
		cin.clear(); cin.ignore(4095, '\n');
		break;
	}
  }
}

class Item {
  private:
    string item{};
	int id{};
	int quantity{};
	double cost{};

  public:
    Item(){
		item = ' ';
		id = 0;
		quantity = 0;
		cost = 0.0;
	}
	Item2(){
		set_name();
    	set_id();
    	set_quantity();
    	set_cost();
    	cin.clear(); cin.ignore(4095, '\n');
	}
    void set_name(){
    	string new_name;
		cout << "Input name: ";
		cin >> new_name;
		item = new_name; 
	}
	void set_id(){
		int new_id;
		bool check {true};
		while (check){
			new_id = get_input<int>("Input id: ");
			if (new_id >= 0) {
    	    	id = new_id;
    	    	check = false;
    	    }
    	    else{
    	    	cout << "Please enter a non-negative id."<<endl;
			}
		}
	}
	void set_quantity(){
		int new_quantity;
		bool check {true};
		while (check){
			new_quantity = get_input<int>("Input quantity: ");
			if (new_quantity >= 0) {
    	    	quantity = new_quantity;
    	    	check = false;
    	    }
    	    else{
    	    	cout << "Please enter a non-negative quantity."<<endl;
			}
		}
	}
	void set_cost(){
		double new_cost;
		bool check {true};
		while (check){
			new_cost = get_input<int>("Input cost: ");
			if (new_cost >= 0) {
        		cost = new_cost;
        		check = false;
        	}
        	else{
        		cout << "Please enter a non-negative cost."<<endl;
			}
		}
	}
	string get_name() {
		return item;
	}
	int get_id() {
		return id;
	}
	int get_quantity() {
		return quantity;
	}
	double get_cost() {
		return cost;
	}
	double get_total_cost(){
		double total_cost{};
		total_cost = quantity * cost;
		return total_cost;
	}
	void display(){
		cout << "name: " << get_name()
				<< "\nID: " << get_id()
				<< "\nquantity: " << get_quantity()
				<< "\ncost: $" << get_cost()
				<< "\ntotal cost: $" << get_total_cost() << endl;
	}
};

int main() {
  	const int MAX_INVENTORY{5};
  	int item_num {};
  	bool check = {true};
  	Item item1, item2, item3, item4, item5;
  	cout << "This program will create up to " << MAX_INVENTORY
    	 << " items and display them to the user.\n\n";
    while(check){
		item_num = get_input<int>("How many items would you like to enter? ");
		switch (item_num){
			case 5:{
				cout << "For item #5: \n";
				item5.Item2();
			}
			case 4:{
				cout << "For item #4: \n";
				item4.Item2();
			}
			case 3:{
				cout << "For item #3: \n";
				item3.Item2();
			}
			case 2:{
				cout << "For item #2: \n";
				item2.Item2();
			}
			case 1:{
				cout << "For item #1: \n";
				item1.Item2();
			}
			case 0:{
				check = false;
				break;
			}
			default:
				cout << "Please enter a number of items between 0 and 5" << endl;
			}
		}
	cout << "\n\n";
    switch (item_num){
		case 5:{
			cout << "For item #5 you entered: \n";
			item5.display();
		}
		case 4:{
			cout << "For item #4 you entered: \n";
			item4.display();
		}
		case 3:{
			cout << "For item #3 you entered: \n";
			item3.display();
		}
		case 2:{
			cout << "For item #2 you entered: \n";
			item2.display();
		}
		case 1:{
			cout << "For item #1 you entered: \n";
			item1.display();
		}
		case 0:{
			cout << "\nThis ends the Item program. Goodbye.\n";
			break;
		}
		default:
			cout << "idk how you got here gg" << endl;
		}
  // system ("pause");
	return 0;
}   // end of main


// Test output below:
/*
This program will create up to 5 items and display them to the user.

How many items would you like to enter? 4
For item #4:
Input name: golf
Input id: 4444
Input quantity: 100
Input cost: 8.99
For item #3:
Input name: baseball
Input id: 3333
Input quantity: 100
Input cost: 25.00
For item #2:
Input name: basketball
Input id: -1
Please enter a non-negative id.
Input id: 2222
Input quantity: -1
Please enter a non-negative quantity.
Input quantity: 10
Input cost: -1
Please enter a non-negative cost.
Input cost: 25.00
For item #1:
Input name: tenis
Input id: -1
Please enter a non-negative id.
Input id: 1111
Input quantity: -1
Please enter a non-negative quantity.
Input quantity: 10
Input cost: -1
Please enter a non-negative cost.
Input cost: 52.25


For item #4 you entered:
name: golf
ID: 4444
quantity: 100
cost: $8
total cost: $800
For item #3 you entered:
name: baseball
ID: 3333
quantity: 100
cost: $25
total cost: $2500
For item #2 you entered:
name: basketball
ID: 2222
quantity: 10
cost: $25
total cost: $250
For item #1 you entered:
name: tenis
ID: 1111
quantity: 10
cost: $52
total cost: $520

This ends the Item program. Goodbye.

--------------------------------
Process exited after 74.96 seconds with return value 0
Press any key to continue . . .
*/
