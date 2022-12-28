// Author:               Jade Shackelford
// Assignment Number:    Lab 14
// File Name:            MW10__L14_Shackelford.cpp  (change DDHH and lastname as appropriate)
// Course/Section:       COSC 1337 Section DDHH (change DDHH to your course identifier)
// Due Date:             See syllabus or blackboard
// Instructor:           Thayer

/*
  For each looping function, provide the code for the equivalent recursive function.
  See Blackboard, Lab 14 for complete instructions.
  
  IMPORTANT: Your recursive functions should NOT use any static local variables
  or global variables! The "state" of the function must be completely self-contained.
  Consider that recursive functions may be called simultaneously by several programs
  at the same time. This occurs when a recursive function is in a library, such
  as qsort(). If calls are not independent, the recursive function is limited
  to a single process.
*/
  
#include <iostream>
#include <iomanip>
using namespace std;

void show_1_to_n_loop(int n) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=1; i<=n; ++i) cout<<i<<" ";
}

void show_1_to_n_recurse(int n) { // recursive
  if (n!=1){
  	int n2= n-1;
  	show_1_to_n_recurse(n2);
  }
  cout << n << " ";
}

void show_n_to_1_loop(int n) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=n; i>=1; --i) cout<<i<<" ";
}

void show_n_to_1_recurse(int n) { // recursive
	cout << n << " ";
	if (n!=1){
		n-=1;
		show_n_to_1_recurse(n);	
	}
}

string reverse_loop(string forward) { // looping, PROVIDED, DO NOT CHANGE
  string backwards;
  int size=forward.size();
  for (int i=0; i<size; ++i) {
    backwards+=forward[size-1-i];
  }
  return backwards;
}

string reverse_recurse(string forward) { // recursive
	int size=forward.size();
	if (size > 1) {
		char copy = forward[0];
		string smaller = forward.erase(0,1);
		string letters = reverse_recurse(smaller);
		string backwards = letters + copy;
		return backwards;
	}
	else {
		return forward;
	}
	// replace this with your return value;  is "" until new code added.
}

int add2_fx(int a, int b) { // functional (for illustration only), PROVIDED, DO NOT CHANGE
  return a+b;
}

int add2_loop(int a, int b) { // looping, PROVIDED, DO NOT CHANGE
  int sum=a;
  if (b>0)
    for (int i=0; i<b; ++i) ++sum;
  else // b<=0
    for (int i=b; i<0; ++i) --sum;
  return sum;
}

int add2_recurse(int a, int b) { // recursive
	int sum=a;
	if (b > 0) {
		sum = a+1;
		b--;
		sum=add2_recurse(sum, b);
	}
	else if (b < 0) {
		sum = a-1;
		b++;
		sum=add2_recurse(sum,b);
	}
  return sum; // replace this with your return value;  is 0 until new code added.
}

int mult2_fx(int a, int b) { // functional (for illustration only), PROVIDED, DO NOT CHANGE
  return a*b;
}

int mult2_loop(int a, int b) { // looping, PROVIDED, DO NOT CHANGE
  int product=0;
  if (b>0)
    for (int i=0; i<b; ++i) product+=a;
  else // b<=0
    for (int i=b; i<0; ++i) product-=a;
  return product;
}

int mult2_recurse(int a, int b) { // recursive
	int product = 0;
	if (b>0) {
		b--;
		product = mult2_recurse(a, b);
		product+=a;
	}
	else if (b<0) {
		b++;
		product = mult2_recurse(a,b);
		product-=a;
	}
  return product; // replace this with your return value;  is 0 until new code added.
}

int search_loop(int array[], int size, int target) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=0; i<size; ++i)
    if (array[i]==target) {return i;}
  return -1;
}

int search_recurse(int array[], int size, int target) { // recursive
	if (size != -1){
		if (array[size] == target){
			return size;
		}
		int newSize = size-1;
		int found = search_recurse(array, newSize, target);
		return found;
	}
	else {
		return size;
	}
	 // replace this with your return value;  is 0 until new code added.
}

enum control_flow_t {functional, looping, recursive};
void show_test(int n, string s, control_flow_t control_flow) {
  // utility function to format test output
  // n: test number; s: "description"; control_flow: functional, looping or recursive
  static const string fx="functional", sl="looping", sr="recursive";
  int max_len=max(fx.size(), max(sl.size(), sr.size()));
  string msg;
  switch (control_flow) {
    case functional: msg=fx;     break;
    case looping:    msg=sl;     break;
    case recursive:  msg=sr;     break;
    default:         msg="??";   break;
  }
  char iorr=msg[0];
  msg=" ("+msg+"): ";
  cout<<"\n"<<n<<iorr<<") "<<s<<setw(max_len+5)<<left<<msg;
}

void infinite_recursion() {
  // try at your own risk! Error message can be interesting.
  infinite_recursion();
}

// This code may be helpful when developing your recursive functions.
void recurse(int times_to_call) {
  // a generalized recursion outline; has 5 locations to do work...
  cout << "recurse head... " << "("<<times_to_call<<") " <<endl; // ALWAYS
  if (times_to_call>1) { // decision to recursive call
    cout << "recurse before call... " << "("<<times_to_call<<") " <<endl;
    recurse(times_to_call-1); // work (problem simplification) can be done inside the parameter list!
    cout << "recurse after call... " << "("<<times_to_call<<") " <<endl;
  } else {
    cout << "recurse else option... " << "("<<times_to_call<<") " <<endl;
  }
  cout << "recurse ...tail " << "("<<times_to_call<<") " <<endl; // ALWAYS
}

int main () {
  cout<<"start...\n";
  
  show_test(1, "show_1_to_n", looping);    show_1_to_n_loop(7);
  show_test(1, "show_1_to_n", recursive);  show_1_to_n_recurse(7);
  cout<<endl;
  
  show_test(2, "show_n_to_1", looping);    show_n_to_1_loop(10);
  show_test(2, "show_n_to_1", recursive);  show_n_to_1_recurse(10);
  cout<<endl;
  
  show_test(3, "reverse", looping);    cout<<reverse_loop("stressed");
  show_test(3, "reverse", recursive);  cout<<reverse_recurse("stressed");
  cout<<endl;

  show_test(4, "add2", functional);
  cout<<add2_fx( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_fx(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_fx(20, -9); cout<<" ";  // correct:  11
  cout<<add2_fx(-7, -5); cout<<" ";  // correct: -12
  show_test(4, "add2", looping);
  cout<<add2_loop( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_loop(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_loop(20, -9); cout<<" ";  // correct:  11
  cout<<add2_loop(-7, -5); cout<<" ";  // correct: -12
  show_test(4, "add2", recursive);
  cout<<add2_recurse( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_recurse(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_recurse(20, -9); cout<<" ";  // correct:  11
  cout<<add2_recurse(-7, -5); cout<<" ";  // correct: -12
  cout<<endl;

  show_test(5, "mult2", functional);
  cout<<mult2_fx( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_fx(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_fx( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_fx(-10, -4); cout<<" ";  // correct:  40
  show_test(5, "mult2", looping);
  cout<<mult2_loop( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_loop(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_loop( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_loop(-10, -4); cout<<" ";  // correct:  40
  show_test(5, "mult2", recursive);
  cout<<mult2_recurse( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_recurse(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_recurse( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_recurse(-10, -4); cout<<" ";  // correct:  40
  cout<<endl;
  
  int primes[] {2, 3, 5, 7, 11, 13, 17}; // some prime numbers to search for
  int size_primes=sizeof(primes)/sizeof(primes[0]); // trick to get #elements in array
  
  show_test(6, "search", looping);
  cout<<search_loop(primes, size_primes, 2)<<", ";
  cout<<search_loop(primes, size_primes, 13)<<", ";
  cout<<search_loop(primes, size_primes, 10);
  show_test(6, "search", recursive);
  cout<<search_recurse(primes, size_primes, 2)<<", ";
  cout<<search_recurse(primes, size_primes, 13)<<", ";
  cout<<search_recurse(primes, size_primes, 10)<<endl;
  
  // uncomment the next line for crash and error message...
  // infinite_recursion();
  
  cout<<"\n...end\n";

  return 0;
} // end of main

// When complete, there will be test output for each of the 6 steps in pairs:
// looping and recursive, as shown below. Your recursive output should match.
/*
start...

1l) show_1_to_n (looping):    1 2 3 4 5 6 7
1r) show_1_to_n (recursive):  1 2 3 4 5 6 7

2l) show_n_to_1 (looping):    10 9 8 7 6 5 4 3 2 1
2r) show_n_to_1 (recursive):  10 9 8 7 6 5 4 3 2 1

3l) reverse (looping):    desserts
3r) reverse (recursive):  desserts

4f) add2 (functional): 9 10 11 -12
4l) add2 (looping):    9 10 11 -12
4r) add2 (recursive):  9 10 11 -12

5f) mult2 (functional): 10 -20 -30 40
5l) mult2 (looping):    10 -20 -30 40
5r) mult2 (recursive):  10 -20 -30 40

6l) search (looping):    0, 5, -1
6r) search (recursive):  0, 5, -1

...end

--------------------------------
Process exited after 0.546 seconds with return value 0
Press any key to continue . . .
...end
*/
