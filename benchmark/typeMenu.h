#pragma once
#ifndef TYPEMENU_H
#define TYPEMENU_H
#include "array.h"
#include "sizeMenu.h"
#include<iostream>

class typeMenu {

public:
	typeMenu();
	~typeMenu();
	void menu(int&);
	void algorithmChoice(int);

private:
	int type;
};

#endif