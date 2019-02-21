#include "typeMenu.h"
#include "array.h"
#include "sizeMenu.h"
#include <iostream>


using std::cout;
using std::cin;
using std::endl;

typeMenu::typeMenu() {} 

typeMenu::~typeMenu() {} 

void typeMenu::menu(int &type){ //menu that takes user input and passes it by reference
	cout << endl << "Types of Array:" << endl;
	cout << "1. Sorted Array" << endl;
	cout << "2. Shuffled Array" << endl;
	cout << "3. Reverse Ordered Array" << endl;
	cout << "4. Sorted and Shuffled at 10% Array" << endl;
	cout << "5. Run all types of Arrays" << endl;
	cout << "Enter a number to select from the following:";
	cin >> type; //takes user input
	switch (type) {
	case 1:
		cout << endl << "---Sorted Array selected---" << endl;
		break;
	case 2:
		cout << endl << "---Shuffled Array selected---" << endl;
		break;
	case 3:
		cout << endl << "---Reverse Ordered Array selected---" << endl;
		break;
	case 4:
		cout << endl << "---Sorted and Shuffled at 10% Array selected---" << endl;
		break;
	case 5:
		cout << endl << "---All types selected---" << endl;
		break;
	default:
		cout << "Invalid input" << endl;
	}
}
void typeMenu::algorithmChoice(int option){ //passes in option from main.cpp 
	menu(type); //pass by ref. of user input
	sizeMenu obj;
	if (type == 5) {
		obj.algorithm_clock_all(option); //fix to run all types
	}
	else {
		obj.algorithm_clock(type, option); //calls function from pass user input to object of sizeMenu
	}
	
}
