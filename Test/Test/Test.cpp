// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class car {

	int testing = 0;

};

int main()
{

	car porsche;
	car *pp = &porsche;

	cout << &porsche;

    return 0;
}

