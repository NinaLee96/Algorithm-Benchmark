#include "array.h"
#include "typeMenu.h"
#include "sizeMenu.h"
#include<iostream>
#include<time.h>

using std::cout;
using std::cin;
using std::endl;


void mainMenu(int &option) { //menu to take user input and store into option then passes it by reference
	typeMenu obj;
	cout << "1. Insertion sort" << endl;
	cout << "2. Selection sort" << endl;
	cout << "3. Bubble sort" << endl;
	cout << "4. Quick sort" << endl;
	cout << "5. Merge sort" << endl;
	cout << "Enter a number to select from the following:";
	cin >> option; //takes user input

	switch (option) {
	case 1:
		cout << endl << "---Insertion sort selected---" << endl;
		obj.algorithmChoice(option); //passes user input into function in typeMenu.h
		break;
	case 2:
		cout << endl << "---Selection sort selected---" << endl;
		obj.algorithmChoice(option);
		break;
	case 3:
		cout << endl << "---Bubble sort selected---" << endl;
		obj.algorithmChoice(option);
		break;
	case 4:
		cout << endl << "---Quick sort selected---" << endl;
		obj.algorithmChoice(option);
		break;
	case 5:
		cout << endl << "---Merge sort selected---" << endl;
		obj.algorithmChoice(option);
		break;
	default:
		cout << endl << "---Invalid selection---" << endl;
	}
}

int main() {
	int option;
	mainMenu(option); 
	//test for algorithms
/*
	array<int> *s = new array<int>(10);
	clock_t start = clock();
	for (int i = 0; i < 1; i++) {
		s->fillReverse();    //change array type to desired
		s->printArray();     //prints the array type
		s->insertionSort();  //change algorithm to desired
		s->printArray();     //prints the sorted array
		//cout << i << endl;  
	}
	clock_t end = clock();
	double ms = double(end - start) / CLOCKS_PER_SEC;
	cout << "100 Iteration completed in: ";
	cout << ms << " s" << endl;
	delete s;
*/
	system("pause");
	return 0;
}