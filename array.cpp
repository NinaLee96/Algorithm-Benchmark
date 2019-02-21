#include "array.h"
#include<iostream>
#include<time.h>
//#include<stdlib.h>
//using namespace std;

template<typename T>
array<T>::array() {} //constructor

template<typename T>
array<T>::array(T num) {
	sizeArray = num;	//passes user input into size
	arrData = new T[sizeArray];	//initializes a new empty array with size
}

template<typename T>
array<T>::~array() {
	delete[] arrData;

} //deconstructor

template<typename T>
T* array<T>::swap(T* arr, T i, T j) { //simple swap function
	T temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return arr;
}

template<typename T>
void array<T>::printArray() {
	for (int i = 0; i < sizeArray; i++) {
		std::cout << arrData[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void array<T>::fillInOrder() { //fills the array in order till it's full
	for (int i = 0; i < sizeArray; i++) {
		T c = i;
		arrData[i] = c;
	}
}

template<typename T>
void array<T>::fillShuffle() { //randomly rills the array up with numbers until it's full
	srand(time(NULL));
	for (int i = 0; i < sizeArray; i++) {
		arrData[i] = rand();
	}

}

template<typename T>
void array<T>::fillReverse() { //fills the array up then reverses the array 
	for (int i = 0; i < sizeArray; i++) {
		arrData[i] = i;
	}
	for (int i = 0; i < sizeArray / 2; i++) { 
		swap(arrData, sizeArray - i - 1, i );
	}
}

template<typename T>
void array<T>::shuffleTenPercent() { 
	for (int i = 0; i < sizeArray; i++) {
		arrData[i] = i;
	}
	srand(time(NULL));
	for (int i = 0; i < (sizeArray * 0.10); i++) { //divides the size of the array by 10% then chooses a random element and swaps it
		int k = rand() % sizeArray;
		swap(arrData, k, i);

	}
}

template<typename T>
void array<T>::insertionSort() {
	int val, j;
	for (int i = 0; i < sizeArray; i++) {
		val = arrData[i]; //stores val for comparison
		j = i - 1; //trails behind i 
		while (j >= 0 && val < arrData[j]) { //swaps if val is smaller than element before it
			arrData = swap(arrData, j + 1, j);
			j--;
		}
	}
}

template<typename T>
void array<T>::selectionSort() {
	int minVal;
	int minIndex;
	for (int i = 0; i < sizeArray; i++) { //loop to swap smallest element with placeholder
		minVal = arrData[i]; //holds smallest value
		minIndex = i;
		for (int j = i + 1; j < sizeArray; j++) { //interates thru array looking for the smallest element
			if (arrData[j] < minVal) {//if element smaller than minVal, change minVal
				minVal = j;
				minIndex = j;
			}
		}
		if (minVal < arrData[i]) {
			swap(arrData, minIndex, i);
		}
	}
}
template<typename T>
void array<T>::bubbleSort() {
	for (int i = 0; i < sizeArray; i++) { //iterates thru array, resets j to zero each iteration
		for (int j = 0; j < sizeArray - 1; j++) { //swaps the bigger element with the next element 
			if (arrData[j] > arrData[j + 1]) {
				swap(arrData, j, j + 1);
			}
		}
	}
}

template<typename T>
T array<T>::partition(T* arrData, int l, int r, int pivot) { 
	while (l <= r) {
		while (arrData[l] < pivot) { //checks to see if element is smaller than pivot, if so, go to next element (right)
			l++;
		}
		while (arrData[r] > pivot) { //checks to see if element is greater than pivot, if so, go to next element (left)
			r--;
		}
		if (l <= r) { // if left element is <= to right then swap the elements and move both left and right towards eachother
			swap(arrData, l, r);
			l++;
			r--;
		}
	}
	return l; //return the left element
/*
	int pivot = arrData[r]; //makes pivot last element
	int pIndex = l;
	for (int i = l; i < r; i++) { //loops and compares if element if less than pivot, if so swap
		if (arrData[i] <= pivot) {
			swap(arrData, i, pIndex);
			pIndex++;
		}
	}
	swap(arrData, pIndex, r); 
	return pIndex;
*/
}

template<typename T>
void array<T>::quickSort(int l, int r) {
	if (l >= r) { //if left is or greater than right, stop recusive call
		return;
	}
	int pivot = arrData[l + (r-l)/ 2]; //picks a pivot in the middle
	int q = partition(arrData, l, r, pivot);  //calls partition function
	quickSort( l, q - 1); //recursive call on left side of array
	quickSort( q + 1, r); //recursive call on right side of array
}

template<typename T>
void array<T>::merge(T* arrData, int l, int m, int r) {
	T* temp = new T[r - l + 1];   //makes a temp array 
	int i = l;  //stores left 
	int j = m + 1; //stores middle
	int k = 0;  //counter for temp array

	while (i <= m && j <= r) { //loop till i meets middle and j meets end of the array
		if (arrData[i] <= arrData[j]) { //puts smaller element into temp array
			temp[k++] = arrData[i++];
		}
		else { //puts bigger element into temp array
			temp[k++] = arrData[j++];
		}
	}

	while (i <= m) { //puts leftover elements of the left array into temp
		temp[k++] = arrData[i++];
	}
	while (j <= r) { //puts leftover elements of the right array into temp
		temp[k++] = arrData[j++];
	}
	for (k = 0, i = l; i <= r; ++i, ++k) { //puts sorted elements from temp array to passed array
		arrData[i] = temp[k];
	}
	delete temp;
}

template<typename T>
void array<T>::mergeSort(int l, int r) {
	if (l < r) { //if array is size of 1, stop
		int mid = (l + r) / 2; //splits array in half
		mergeSort(l, mid); //splits left side of the array
		mergeSort(mid + 1, r); //splits right side of the arrDataay
		merge(arrData, l, mid, r); //calls merge
	}
}
template class array<char>; //instantiate what data type to use
template class array<int>;  //instantiate what data type to use