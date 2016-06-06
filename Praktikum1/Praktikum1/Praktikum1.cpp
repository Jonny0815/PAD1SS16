

#include "stdafx.h"
#include <string>
#include <iostream>



using namespace std;


class student {

	

public: 

	student *next = NULL;
	student *prev = NULL;
	string name = "                     ";
	string lastname = "                       ";
	char gender = 0;
	int mnumber = 0;
	int finalmark = 0;




	//work functions
	int list_student() {

		cout << endl;
		cout << "Vorname        : " << name << endl;
		cout << "Nachname       : " << lastname << endl;
		cout << "Geschlecht     : " << gender << endl;
		cout << "Matrikelnummer : " << mnumber << endl;
		cout << "Abschlussnote  : " << finalmark << endl<< endl;
		cout << "---------------------------------------------------------" << endl;
		
		if (next != NULL) {
			next->list_student();
		}
		

		return 0;

	};
	
	int search_student(int mnr) {

		if (mnumber == mnr) {

			cout << endl;
			cout << "Vorname        : " << name << endl;
			cout << "Nachname       : " << lastname << endl;
			cout << "Geschlecht     : " << gender << endl;
			cout << "Matrikelnummer : " << mnumber << endl;
			cout << "Abschlussnote  : " << finalmark << endl << endl;
			cout << "---------------------------------------------------------" << endl;

		}
		else {

			next->search_student(mnr);

		}

		return 0;
	};
	int edit_student() {

		return 0;

	};
	int import_student() {

		return 0;

	};
	int export_student() {

		return 0;

	};
	

};



int menu();
int list_student();
int add_student();
int search_student();
int edit_student();
int import_student();
int export_student();


student *head = NULL;
student *tail = NULL;

int main()
{
	
	
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
	case 1: list_student();
		break;
	case 2: add_student();
		break;
	case 3: search_student();
		break;
	case 4: edit_student();
		break;
	case 5: import_student();
		break;
	case 6: export_student();
		break;
	case 7: 
		break;
	}


	return 0;

};


int list_student() {

	cout << "---------------------------------------------------------" << endl;
	cout << "                  Studentenauflistung                    " << endl;
	cout << "---------------------------------------------------------" << endl << endl;

	head->list_student();
	
	menu();

	return 0;
};

int add_student() {

	student *pstud = new student;
	string name;
	string lastname;
	char gender;
	int nr;
	int finalgrade;
	cout << "---------------------------------------------------------" << endl;
	cout << "                  Studenten hinzufügen                   " << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	cout << "Vorname        : ";
	cin >> name;
	pstud->name = name;
	cout <<"Nachname       : ";
	cin >> lastname;
	pstud->lastname = lastname;
	cout <<"Geschlecht     : ";
	cin >> gender;
	pstud->gender = gender;
	cout <<"Matrikelnummer : ";
	cin >> nr;
	pstud->mnumber = nr;
	cout <<"Abschlussnote  : ";
	cin >> finalgrade;
	pstud->finalmark = finalgrade;

	

	if (head == NULL) {

		head = pstud;
		tail = pstud;

	}
	else {

		pstud->next = head;
		head->prev = pstud;
		head = pstud;

	}

	menu();

	return 0;

};
int search_student() {

	cout << "---------------------------------------------------------" << endl;
	cout << "                  Studenten suchen                       " << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	cout << "Zu suchende Matrikelnummer eingeben: ";
		int mnr;
		cin >> mnr;
	head->search_student(mnr);

	menu();

	return 0;

};
int edit_student() {

	cout << "---------------------------------------------------------" << endl;
	cout << "                  Studenten bearbeiten                       " << endl;
	cout << "---------------------------------------------------------" << endl << endl;
	cout << "Matrikelnummer des zu bearbeitenden Studenten eingeben: ";
	int mnr;

	return 0;

};
int import_student() {

	return 0;

};
int export_student() {

	return 0;

};
