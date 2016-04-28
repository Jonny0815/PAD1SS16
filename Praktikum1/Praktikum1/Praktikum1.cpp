// Praktikum1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>



using namespace std;


class student {

	

private: 

	student *next;
	string name = "                     ";
	string lastname = "                       ";
	char gender = 0;
	int mnumber = 0;
	int finalmark = 0;


public:


	//set functions
	int setnext(student h_next) {
	
		*next = h_next;

		return 0;
	
	};
	int setname(string h_name) {

		name = h_name;

		return 0;

	};
	int setlastname(string h_lastname) {

		lastname = h_lastname;

		return 0;

	};
	int setgender(char h_gender) {

		gender = h_gender;

		return 0;

	};
	int setmnumber(int h_mnumber) {

		mnumber = h_mnumber;

		return 0;

	};
	int setfinalmark(int h_finalmark) {

		finalmark = h_finalmark;

		return 0;

	};

	//get functions
	student getnext() {

		return *next;

	};
	string getname() {

		return name;

	};
	string getlastname() {

		return lastname;

	};
	char getgender() {

		return gender;

	};
	int getmnumber() {

		return mnumber;

	};
	int getfinalmark() {

		return finalmark;

	};

	//work functions
	int list_student() {

		cout << endl;
		cout << "Vorname: " << name << endl;
		cout << "Nachname: " << lastname << endl;
		cout << "Geschlecht: " << gender << endl;
		cout << "Matrikelnummer: " << mnumber << endl;
		cout << "Abschlussnote: " << finalmark << endl<< endl;
		cout << "---------------------------------------------------------" << endl;


	};
	int add_student();
	student search_student();
	student edit_student();
	int import_student();
	int export_student();


};

class head{

private:

	student *next;

public:

	int list_student() {

		next.list_student();

	};
	int add_student();
	student search_student();
	student edit_student();
	int import_student();
	int export_student();

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

	student *head = new student;
	
	menu();

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


int list_student() {

	cout << "---------------------------------------------------------" << endl;
	cout << "                  Studentenauflistung                    " << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	

};
