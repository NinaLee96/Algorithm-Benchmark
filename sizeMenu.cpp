#include "sizeMenu.h"
#include "array.h"
#include "typeMenu.h"
#include<iostream>
#include<time.h>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;

sizeMenu::sizeMenu() {}

sizeMenu::~sizeMenu(){}

void sizeMenu::menu(int& num){ //menu takes user input and assigns num to what the user chooses (pass by reference of num)
	int choice;
	cout << endl << "Size of Array:" << endl;
	cout << "1. 10" << endl;
	cout << "2. 1,000" << endl;
	cout << "3. 10,000" << endl;
	cout << "4. 100,000" << endl;
	cout << "5. 1,000,000" << endl;
	cout << "Enter a number to select an array size from the following:";
	cin >> choice; //takes user input

	switch (choice) {
	case 1:
		cout << endl << "---Array size 10 selected---" << endl;
		num = 10; 
		break;
	case 2:
		cout << endl << "---Array size 1,000 selected---" << endl;
		num = 1000;
		break;
	case 3:
		cout << endl << "---Array size 10,000 selected---" << endl;
		num = 10000;
		break;
	case 4:
		cout << endl << "---Array size 100,000 selected---" << endl;
		num = 100000;
		break;
	case 5:
		cout << endl << "---Array size 1,000,000 selected---" << endl;
		num = 1000000;
		break;
	default:
		cout << "Invalid Selection" << endl;
	}
}

void sizeMenu::passType(array<int>* func, int type){ //passes the array created in the function and the type from typeMenu.cpp
	switch (type) { //decides which array type to use depending what the user chooses
	case 1:
		func->fillInOrder();
		break;
	case 2:
		func->fillShuffle();
		break;
	case 3:
		func->fillReverse();
		break;
	case 4:
		func->shuffleTenPercent();
		break;
	default:
		std::cerr << "Invalid input" << endl;
	}
}

void sizeMenu::passAlgor(array<int>* func, int option) {
	switch (option) { //decides which algorithm to use depending what the user chooses
	case 1:
		func->insertionSort();
		break;
	case 2:
		func->selectionSort();
		break;
	case 3:
		func->bubbleSort();
		break;
	case 4:
		func->quickSort(0, num-1);
		break;
	case 5:
		func->mergeSort(0, num-1);
		break;
	default:
		cout << "Invalid input" << endl;
	}
}

void sizeMenu::algorithm_clock(int type, int option) { //function times the algorithm and array time chosen
	menu(num); //calls menu and passes num
	std::ofstream myfile;
	myfile.open("test.csv"); //opens file
	cout << endl << "Running 100 iteration of the array type...";
	array<int> *s = new array<int>(num); //uses num in menu() as pass by reference
	myfile << ", ,";
	for (int i = 0; i < 100; i++) {
		clock_t start = clock(); //initates the clock to start
		passType(s, type);
		passAlgor(s, option);
		clock_t end = clock(); //stops the clock
		double ms = double(end - start) / CLOCKS_PER_SEC; //subtracts the end from the start time and calculates the time
		myfile << "," << ms;
	}
	cout << "done" << endl;
	myfile.close();
	delete s;
}

void sizeMenu::algorithm_clock_all(int option) { //runs all types of arrays and gets the time for each array types
	menu(num);
	//cout << endl << "Running 100 iteration of the array type..." << endl;
	array<int> *s = new array<int>(num); //uses num in menu() as pass by reference
	int k = 1;
	std::ofstream myfile;
	myfile.open("test.csv");
	myfile << endl;
	while (k < 5) { //loop picks all 4 choices of array types
		cout << endl << "Running 100 iteration of the array types...";
		myfile << ", ,";
		for (int i = 0; i < 100; i++) {
			clock_t start = clock(); //initates the clock to start
			passType(s, k); 
			passAlgor(s, option);
			clock_t end = clock(); //stops the clock
			double ms = double(end - start) / CLOCKS_PER_SEC;
			myfile << "," << ms;
		}
		myfile << endl;
		k++;
		cout << "done" << endl;
	}
	myfile.close();
	delete s;
	//double ms = double(end - start) / CLOCKS_PER_SEC; //subtracts the end from the start time and calculates the time
	//cout << "100 Iteration completed in: ";
	//cout << ms << " ms" << endl;
}

