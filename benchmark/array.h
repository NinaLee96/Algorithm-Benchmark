
#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>

template<typename T>
class array{

public:
	array();	//default constructor
	array(T);   //copy constructor with int passed in
	~array();   //deconstructor 

	//fill array functions
	T* swap(T*, T, T);
	void printArray();
	void fillInOrder();
	void fillShuffle();
	void fillReverse();
	void shuffleTenPercent();

	//sorting algorithm functions
	void insertionSort();
	void selectionSort();
	void bubbleSort();
	T partition(T*, int, int, int);
	void quickSort( int, int);
	void merge(T*, int, int, int);
	void mergeSort(int , int );

private:
	int sizeArray;
	T* arrData;

};

#endif // !ARRAY_H
