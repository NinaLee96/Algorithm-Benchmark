#pragma once
#ifndef SIZEMENU_H
#define SIZEMENU_H
#include "typeMenu.h"
#include<iostream>

class sizeMenu {

public:
	sizeMenu();
	~sizeMenu();
	void menu(int&);
	void passType(array<int>*, int);
	void passAlgor(array<int>*, int);
	void algorithm_clock(int, int);
	void algorithm_clock_all(int);

private:
	int num;
};


#endif