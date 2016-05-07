// Praktikum2.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

int main()
{
	const int anzahl_studenten = 10;

	struct Student
	{
		string firstname;
		string lastname;
		char sex;
		int matriculation_number = -1;
		float final_mark = -1;

	};


	Student students[anzahl_studenten];


	students[0].firstname = "Daniel";
	students[0].lastname = "Kreis";
	students[0].sex = 'm';
	students[0].matriculation_number = 12346;
	students[0].final_mark = 1.3;


	//Req04
	string firstname;
	string lastname;
	char sex;
	int matriculation_number;
	float final_mark;



	cout << "Student eingeben" << endl;
	cout << "  Firstname            => ";
	cin >> firstname;
	cout << "  Lastname             => ";
	cin >> lastname;
	cout << "  Sex                  => ";
	cin >> sex;
	cout << "  Matriculation Number => ";
	cin >> matriculation_number;
	cout << "  Final Mark           => ";
	cin >> final_mark;

	// Suche freien Speicherplatz

	// Req 03
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





	// Req 03
	for (int i = 0; i < anzahl_studenten; i++)
	{
		cout << "Student " << i << endl;
		cout << "  Firstname            => " << students[i].firstname << endl;
		cout << "  Lastname             => " << students[i].lastname << endl;
		cout << "  Sex                  => " << students[i].sex << endl;
		cout << "  Matriculation Number => " << students[i].matriculation_number << endl;
		cout << "  Final Mark           => " << students[i].final_mark << endl;
	}


	return 0;
}

