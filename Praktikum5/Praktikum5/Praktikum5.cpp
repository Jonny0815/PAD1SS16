

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


ifstream file_data;
fstream file_export;


class student;
class slist;






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
		cout << "Abschlussnote  : " << finalmark << endl << endl;
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
			if (next != NULL) {
				next->search_student(mnr);
			}
		}


		return 0;
	};

	student edit_student(int mnr) {

		

		if (mnumber == mnr) {

			return *this;
		}

		else {

			if (next != NULL) {
				next->edit_student(mnr);
			}
		}


		

	};

	int export_student() {



		file_export.open("export.csv");


		file_export << name << ";";
		file_export << lastname << ";";
		file_export << gender << ";";
		file_export << mnumber << ";";
		file_export << finalmark << ";";


		file_export.close();

		if (next != NULL) {
			next->export_student();
		}



		return 0;

	};


};

class slist {

private:

	student *head = NULL;
	student *tail = NULL;

public:



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

		if (head != NULL) {
			head->list_student();
		}
		else {

			cout << "Keine Studenten in der Liste" << endl;
		};

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
		cout << "Nachname       : ";
		cin >> lastname;
		pstud->lastname = lastname;
		cout << "Geschlecht     : ";
		cin >> gender;
		pstud->gender = gender;
		cout << "Matrikelnummer : ";
		cin >> nr;
		pstud->mnumber = nr;
		cout << "Abschlussnote  : ";
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
	int edit_student() { return 0; };
	int import_student() {

		string input_storage = "";
		int zaehler_feld = 0;
		string name;
		string lastname;
		char gender;
		int mnr;
		float fm;



		cout << "---------------------------------------------------------" << endl;
		cout << "                  Studenten importieren                  " << endl;
		cout << "---------------------------------------------------------" << endl << endl;

		file_data.open("data.csv", ios::in);
		if (file_data) {
			while (getline(file_data, input_storage, ';'))
			{
				if (zaehler_feld == 0)
					name = input_storage;
				if (zaehler_feld == 1)
					lastname = input_storage;
				if (zaehler_feld == 2)
					gender = input_storage.at(0);
				if (zaehler_feld == 3)
					mnr = atoi(input_storage.c_str());
				if (zaehler_feld == 4)
					fm = atof(input_storage.c_str());
				zaehler_feld++;
				if (zaehler_feld > 4) {

					student *stud = new student;
					stud->name = name;
					stud->lastname = lastname;
					stud->gender = gender;
					stud->mnumber = mnr;
					stud->finalmark = fm;



					if (head == NULL) {

						head = stud;
						tail = stud;

					}
					else {

						stud->next = head;
						head->prev = stud;
						head = stud;

					}


					zaehler_feld = 0;
				}
			}
			file_data.close();




		}
		else {
			cout << "Fehler beim Lesen! \n" << endl;
		}


		menu();


		return 0;

	};
	int export_student() {


		cout << "---------------------------------------------------------" << endl;
		cout << "                  Studenten exportieren                  " << endl;
		cout << "---------------------------------------------------------" << endl << endl;


		head->export_student();



		return 0;

	};


};


int main()
{
	slist studlist;

	studlist.menu();

	return 0;
}