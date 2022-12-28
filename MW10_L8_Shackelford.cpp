/*
  Programmer:			Jade Shackelford
  Assignment:           Lab 8
  Topic:                Implement and test class Item
  File Name:            MW10_L9_Shackelford.cpp
  Course/Section:       COSC 1337; Section MW10
  Due Date:             See syllabus or blackboard
  Instructor:           Thayer
*/

// Compiler directives
#include <iostream> // for cin, cout, endl
#include <iomanip>
#include <string>
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

class Board {
  private:
  	char tic_tac [3][3];
    
  public:
  	Board() {
		for (int i=0; i<=2; i++){
  			for (int n=2; n>=0; n--){
	  			tic_tac [i][n] = '*';
	  		}
		}
	}
	
	char get(int num) {
		int row = get_row(num);
		int column = get_column(num);
		if (tic_tac[row][column] != '*') {
			return tic_tac[row][column];
		}
		else {
			return swap(num);
		}
	}
	
	char swap(int num) {
		switch (num) {
			case 1: {
				return '1';
			}
			case 2: {
				return '2';
			}
			case 3: {
				return '3';
			}
			case 4: {
				return '4';
			}
			case 5: {
				return '5';
			}
			case 6: {
				return '6';
			}
			case 7: {
				return '7';
			}
			case 8: {
				return '8';
			}
			case 9: {
				return '9';
			}
		}
	}
	
	int get_row(int num) {
		if (num >= 6) {
			return 0;
		}
		else if (num >= 3) {
			return 1;
		}
		else {
			return 2;
		}
	}
	
	int get_column(int num) {
		if (num == 7 || num == 4 || num == 1) {
			return 0;
		}
		else if (num == 8 || num == 5 || num == 2) {
			return 1;
		}
		else {
			return 2;
		}
	}
	
	bool win() {
		if(get(7) == get(8) && get(8) == get(9)){
			return false;
		}
		else if(get(4) == get(5) && get(5) == get(6)) {
			return false;
		}
		else if(get(1) == get(2) && get(2) == get(3)) {
			return false;
		}
		else if(get(7) == get(4) && get(4) == get(1)) {
			return false;
		}
		else if(get(8) == get(5) && get(5) == get(2)) {
			return false;
		}
		else if(get(9) == get(6) && get(6) == get(3)) {
			return false;
		}
		else if(get(7) == get(5) && get(5) == get(3)) {
			return false;
		}
		else if(get(9) == get(5) && get(5) == get(1)) {
			return false;
		}
		else {
			return true;
		}
	}
	
	void set(int num, int player) {
		int row = get_row(num);
		int column = get_column(num);
		if (player == 1) {
			tic_tac[row][column] = 'X';
		}
		else {
			tic_tac[row][column] = 'O';
		}
	}
	
	void reset() {
		for (int i=0; i<=2; i++){
  			for (int n=2; n>=0; n--){
	  			tic_tac [i][n] = '*';
	  		}
		}
	}
	
	void display() {
		cout << "\n " << get(7) << " | " << get(8) << " | " << get(9)
				<< "\n ---------\n " << get(4) << " | " << get(5) << " | " << get(6)
				<< "\n ---------\n " << get(1) << " | " << get(2) << " | " << get(3);
	}
};

int main() {
	Board b1;
	bool check {true}, restart {true}, turn {true};
	char cont {' '};
	int player {1}, player_1_score {0}, player_2_score {0}, num {0};
	cout << "Welcome! This program simulates a game of tic tac toe and keeps score.\n"
		 << "Player 1 will be Xs and Player 2 will be Os.\n"
		 << "At the end of each game you will be shown the current score and asked if you'd like to play again.\n\n";
	while (check){
		restart = {true};
		while (b1.win()){
			num = 0;
			turn = true;
			while (turn){
				b1.display();	
				if (player == 1){
					num = getinput<int>("\nPlayer 1 please pick a number for your turn: ", "Please pick a valid number between 1-9.");
					if (num >=1 && num <=9){
						if (b1.get(num) != 'X' && b1.get(num) != 'O'){
							b1.set(num, player);
							player = 2;
							turn = false;
						}
						else {
							cout << "Please pick a valid number between 1-9 that hasn't already been selected.\n";
						}
					} else {
						cout << "Please pick a valid number between 1-9.\n";
					}
				} else {
					num = getinput<int>("\nPlayer 2 please pick a number for your turn: ", "Please pick a valid number between 1-9.");
					if (num >=1 && num <=9){
						if (b1.get(num) != 'X' && b1.get(num) != 'O'){
							b1.set(num, player);
							player = 1;
							turn = false;
						} else {
							cout << "Please pick a valid number between 1-9 that hasn't already been selected.\n";
						}
					} else {
						cout << "Please pick a valid number between 1-9.\n";
					}
				}
			}
		}
		if (player == 1){
			cout << "\n Player 2 wins!" << endl;
			player_2_score++;
		}
		else {
			cout << "\n Player 1 wins!" <<endl;
			player_1_score++;
		}
		cout << "Player 1 score: " << player_1_score << "\nPlayer 2 score: " << player_2_score << "\n\n";
		while(restart) { 
			cont = getinput<char>("Would you like to play again? [Y/N]: ", "Please enter a valid answer  [Y/N]: ");
			switch (tolower(cont)){
				case 'y':{
					restart = {false};
					b1.reset();
					break;
				}
				case 'n':{
					restart = {false};
					check = {false};
					break;
				}
				default:
					cout << "Please enter a valid answer  [Y/N]: ";
			}
		}
	}
	cout << "Goodbye!";	
	return 0;
}   // end of main


// Test output below:
/*
Welcome! This program simulates a game of tic tac toe and keeps score.
Player 1 will be Xs and Player 2 will be Os.
At the end of each game you will be shown the current score and asked if you'd like to play again.


 7 | 8 | 9
 ---------
 4 | 5 | 6
 ---------
 1 | 2 | 3
Player 1 please pick a number for your turn: 7

 X | 8 | 9
 ---------
 4 | 5 | 6
 ---------
 1 | 2 | 3
Player 2 please pick a number for your turn: 5

 X | 8 | 9
 ---------
 4 | O | 6
 ---------
 1 | 2 | 3
Player 1 please pick a number for your turn: 8

 X | X | 9
 ---------
 4 | O | 6
 ---------
 1 | 2 | 3
Player 2 please pick a number for your turn: 1

 X | X | 9
 ---------
 4 | O | 6
 ---------
 O | 2 | 3
Player 1 please pick a number for your turn: 5
Please pick a valid number between 1-9 that hasn't already been selected.

 X | X | 9
 ---------
 4 | O | 6
 ---------
 O | 2 | 3
Player 1 please pick a number for your turn: 9

 Player 1 wins!
Player 1 score: 1
Player 2 score: 0

Would you like to play again? [Y/N]: y

 7 | 8 | 9
 ---------
 4 | 5 | 6
 ---------
 1 | 2 | 3
Player 2 please pick a number for your turn: 1

 7 | 8 | 9
 ---------
 4 | 5 | 6
 ---------
 O | 2 | 3
Player 1 please pick a number for your turn: a
Please pick a valid number between 1-9.

Player 1 please pick a number for your turn: 2

 7 | 8 | 9
 ---------
 4 | 5 | 6
 ---------
 O | X | 3
Player 2 please pick a number for your turn: 3

 7 | 8 | 9
 ---------
 4 | 5 | 6
 ---------
 O | X | O
Player 1 please pick a number for your turn: 5

 7 | 8 | 9
 ---------
 4 | X | 6
 ---------
 O | X | O
Player 2 please pick a number for your turn: 4

 7 | 8 | 9
 ---------
 O | X | 6
 ---------
 O | X | O
Player 1 please pick a number for your turn: 8\

 Player 1 wins!
Player 1 score: 2
Player 2 score: 0

Would you like to play again? [Y/N]: Please enter a valid answer  [Y/N]: Would you like to play again? [Y/N]: n
Goodbye!
--------------------------------
Process exited after 41.13 seconds with return value 0
Press any key to continue . . .
*/
