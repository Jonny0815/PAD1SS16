#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct Student
{
	string firstname;
	string lastname;
	char sex;
	int matriculation_number = -1;
	float final_mark = -1;
};

int main()
{
	
	const int anzahl_studenten = 10;
	int anzahl,
		i = 0;

	ifstream file_data;


	fstream file_export;



	string firstname; 
	string lastname;
	char sex;
	int matriculation_number = -1;
	float final_mark = -1;

	bool full_storage = false;


	string input_storage = "";
	int zaehler_feld = 0;
	int zaehler_student = 0;

	string output_storage = "";

	
	Student students[anzahl_studenten];

	students[0].firstname = "Daniel"; 
	students[0].lastname = "Mueller";
	students[0].sex = 'm';
	students[0].matriculation_number = 12345;
	students[0].final_mark = 1.3;

	int menue_choice = 0;
	while (menue_choice != 7) {
		cout << "----------------------------------" << endl;
		cout << "-   Studentenverwaltung V0.3     -" << endl;
		cout << "----------------------------------" << endl;
		cout << "1) Student(in) auflisten" << endl;
		cout << "2) Student(in) anlegen" << endl;
		cout << "3) Student(in) suchen" << endl;
		cout << "4) Student(in) bearbeiten" << endl;
		cout << "5) Studierende importieren" << endl;
		cout << "6) Studierende exportieren" << endl;
		cout << "7) Programmende" << endl;
		cout << "Bitte waehlen Sie ein Menuepunkt aus:";
		cin >> menue_choice;
		cout << "Eingabe = " << menue_choice << endl;

		switch (menue_choice) {

	
		case 1:
		{
			cout << "1) Student(in) auflisten" << endl;
			for (int i = 0; i < anzahl_studenten; i++) {
				cout << "Student" << i << endl;
				cout << "Vorname:             => " << students[i].firstname << endl;
				cout << "Nachname:            => " << students[i].lastname << endl;
				cout << "Geschlecht:          => " << students[i].sex << endl;
				cout << "Matrikelnummer:      => " << students[i].matriculation_number << endl;
				cout << "Abschlussnote:       => " << students[i].final_mark << endl;

			}


		};
		break;

	
		case 2:
		{
			cout << "2) Student(in) anlegen\n" << endl;
			

			cout << "Student" << i << endl;
			cout << "Vorname:             => " << endl;
			cin >> firstname;
			cout << "Nachname:            => " << endl;
			cin >> lastname;
			cout << "Geschlecht:          => " << endl;
			cin >> sex;
			cout << "Matrikelnummer:      => " << endl;
			cin >> matriculation_number;
			cout << "Abschlussnote:       => " << endl;
			cin >> final_mark;

			for (int i = 0; i < anzahl_studenten; i++)
			{
				
				if (students[i].matriculation_number == -1)
				{
					students[i].firstname = firstname; 
					students[i].lastname = lastname;
					students[i].sex = sex;
					students[i].matriculation_number = matriculation_number;
					students[i].final_mark = final_mark;


					
					break;
				}

			}

			if (i >= anzahl_studenten - 1 && students[i].matriculation_number != -1) 
			{
				full_storage = true;
				cout << "Kein freier Speicherplatz vorhanden" << endl;
				cout << "Vorgang wird abgebrochen \n" << endl;
			}
		};
		break;

		case 3:
		{
			cout << "3) Student(in) suchen" << endl;
		};
		break;

		case 4:
		{
			cout << "4) Student(in) bearbeiten" << endl;
		}
		break;

		case 5:
		{
			cout << "5) Studierende importieren" << endl;

			file_data.open("data.csv", ios::in);
			if (file_data) {
				while (getline(file_data, input_storage, ';')) 
				{
					if (zaehler_feld == 0)
						students[zaehler_student].firstname = input_storage;
					if (zaehler_feld == 1)
						students[zaehler_student].lastname = input_storage;
					if (zaehler_feld == 2)
						students[zaehler_student].sex = input_storage.at(0);
					if (zaehler_feld == 3)
						students[zaehler_student].matriculation_number = atoi(input_storage.c_str()); 
					if (zaehler_feld == 4)
						students[zaehler_student].final_mark = atof(input_storage.c_str()); 
					zaehler_feld++;
					if (zaehler_feld > 4) {
						zaehler_feld = 0;
						zaehler_student++;
					}
				}
				file_data.close(); 
			}
			else {
				cout << "Fehler beim Lesen! \n" << endl;
			}

			for (int i = 0; i < 10; i++) {
				cout << "Student " << i << endl;
				cout << "Vorname                => " << students[i].firstname << endl;
				cout << "Nachname               => " << students[i].lastname << endl;
				cout << "Geschlecht             => " << students[i].sex << endl;
				cout << "Matrikulationsnummer   => " << students[i].matriculation_number << endl;
				cout << "Abschlussnote          => " << students[i].final_mark << endl;
				cout << "\n" << endl;
			}
		}
		break;

		
		case 6:
		{
			cout << "6) Studierende exportieren" << endl;

			file_export.open("export.csv");

			for (int i = 0; i < anzahl_studenten; i++)
			{
				file_export << students[i].firstname << ";";
				file_export << students[i].lastname << ";";
				file_export << students[i].sex << ";";
				file_export << students[i].matriculation_number << ";";
				file_export << students[i].final_mark << ";";
			}


			file_export.close();

			break;
		}


		case 07:
		{
			cout << "7) Programmende" << endl;
			cout << "Es wurde Menüpunkt " << menue_choice << " ausgewählt." << endl;
			cout << "Das Programm wird beendet." << endl;

			break;
		}

		default:
		{
			cout << "Eingabefehler" << endl;
			break;
		}
		}


	}





	return 0;
}
