//Author: Twee Shackelford; 
//Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
//Lab: 2
//Purpose: This program draws diamonds using simple ASCII

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int line{1};
	while (line>0) {
		cout<<"Enter the number of rows desired to make a diamond pattern (0 to quit):";
		cin >> line;
		int remainder{line%2};
		int stars, spaces, i;
		if  (line>0 && remainder==0) {
			//even check
			spaces = (line/2)-1;
			for (stars = 2; stars <= line; stars+=2){
				//growing half
				for (i=1; i<= spaces; i++){
					cout<<' ';
				}
				for (i=1; i<= stars; i++){
					cout<<'*';
				}
				cout<<endl;
				spaces-=1;
			}
			spaces = 0;
			for (stars = line; stars >= 2; stars-=2){
				//shrinking half
				for (i=1; i<= spaces; i++){
					cout<<' ';
				}
				for (i=1; i<= stars; i++){
					cout<<'*';
				}
				cout<<endl;
				spaces+=1;
			}
			cout<<"\n\n";
		}
		else if (line>0 && remainder==1) {
			//odd check
			spaces = (line-1)/2;
			for (stars = 1; stars < line; stars+=2){
				//growing half
				for (i=1; i<= spaces; i++){
					cout<<' ';
				}
				for (i=1; i<= stars; i++){
					cout<<'*';
				}
				cout<<endl;
				spaces-=1;
			}
			spaces = 0;
			for (stars = line; stars >= 1; stars-=2){
				//shrinking half
				for (i=1; i<= spaces; i++){
					cout<<' ';
				}
				for (i=1; i<= stars; i++){
					cout<<'*';
				}
				cout<<endl;
				spaces+=1;
			}
			cout<<"\n\n";
		}
		else
			break;
	}
}

/*
Enter the number of rows desired to make a diamond pattern (0 to quit):5
  *
 ***
*****
 ***
  *


Enter the number of rows desired to make a diamond pattern (0 to quit):7
   *
  ***
 *****
*******
 *****
  ***
   *


Enter the number of rows desired to make a diamond pattern (0 to quit):1
*


Enter the number of rows desired to make a diamond pattern (0 to quit):2
**
**


Enter the number of rows desired to make a diamond pattern (0 to quit):3
 *
***
 *


Enter the number of rows desired to make a diamond pattern (0 to quit):4
 **
****
****
 **


Enter the number of rows desired to make a diamond pattern (0 to quit):0

--------------------------------
Process exited after 27.67 seconds with return value 0
Press any key to continue . . .
*/
