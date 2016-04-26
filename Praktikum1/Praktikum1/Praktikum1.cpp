// Praktikum1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>



using namespace std;


class student {

private: 
	string name = "                     ";
	string lastname = "                       ";
	char gender = 0;
	int mnumber = 0;
	int finalmark = 0;

public:

	//set functions
	int setname();
	int setlastname();
	int setgender();
	int setmnumber();
	int setfinalmark();

	//get functions
	string getname();
	string getlastname();
	char getgender();
	int getmnumber();
	int getfinalmark();


};

int menu();
int list_student();
int add_student();
student search_student();
student edit_student();
int import_student();
int export_student();

int main()
{

	menu();

    return 0;
}




int student::setlastname()
{
	return 0;
}



int menu() {

	int menuselect = 0;

	cout << "---------------------------------------------------------" << endl;
	cout << "                  Studentenverwaltung                    " << endl;
	cout << "---------------------------------------------------------" << endl<<endl;
	cout << "1) Studenten auflisten" << endl;
	cout << "2) Studenten anlegen" << endl;
	cout << "3) Studenten suchen" << endl;
	cout << "4) Studenten bearbeiten" << endl;
	cout << "5) Studenten importieren" << endl;
	cout << "6) Studenten exportieren" << endl;
	cout << "7) Pr0gramm beenden" << endl<<endl;
	cout << "Auswahl: ";
	cin >> menuselect;
	

	switch (menuselect) {
	case '1': list_student();
		break;
	case '2': add_student();
		break;
	case '3': search_student();
		break;
	case '4': edit_student();
		break;
	case '5': import_student();
		break;
	case'6': export_student();
		break;
	case'7': 
		break;
	}


	return 0;

};