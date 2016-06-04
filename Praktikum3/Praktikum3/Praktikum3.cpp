// Praktikum3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct student
{
	student *next = NULL;
	student *prev = NULL;
	string firstname;
	string lastname;
	char sex;
	int matriculation_number = -1;
	float final_mark = -1;
};


//declaring functions 

int menu();
int list_student();
int add_student();
student search_student();
student edit_student();
int import_student();
int export_student();




//initialising list

student *head = new student;
student *tail = new student;


int main()
{





	menu();

    return 0;
}


int menu() {

	int menuselect = 0;

	cout << "---------------------------------------------------------" << endl;
	cout << "                  Studentenverwaltung                    " << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	cout << "1) Studenten auflisten" << endl;
	cout << "2) Studenten anlegen" << endl;
	cout << "3) Studenten suchen" << endl;
	cout << "4) Studenten bearbeiten" << endl;
	cout << "5) Studenten importieren" << endl;
	cout << "6) Studenten exportieren" << endl;
	cout << "7) Pr0gramm beenden" << endl << endl;
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


int list_student(student h_head) {






	return 0;
};

int add_student() {

	student new_stud;

	cout << "---------------------------------------------------------" << endl;
	cout << "                  Neuen Studenten anlegen                " << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	cout << "Vorname        :  ";
	cin >> new_stud.firstname;
	cout << endl;
	cout << "Nachname       : " ;
	cin >> new_stud.lastname;
	cout << endl;
	cout << "Geschlecht     : " ;
	cin >> new_stud.sex;
	cout << endl;
	cout << "Matrikelnummer : " ;
	cin >> new_stud.matriculation_number;
	cout << endl;
	cout << "Abschlussnote  : " ;
	cin >> new_stud.final_mark;
	cout << endl;
	if (head->next == NULL) {

		head->next = &new_stud;
		tail->prev = &new_stud;

	}
	else {
		student *temp_stud = head->next;
		new_stud.next = temp_stud;
		head->next = &new_stud;
		new_stud.prev = head;
		temp_stud->prev = &new_stud;

	};



	return 0;
};