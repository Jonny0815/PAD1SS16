#ifndef student_h
#define student_h

class student {
public:

	student *next = NULL;
	student *prev = NULL;
	string name = "                     ";
	string lastname = "                       ";
	char gender = 0;
	int mnumber = 0;
	int finalmark = 0;

	list_student();
	search_student(int mnr);
	export_student();
	edit_student(int mnr);



};



#endif // !student_h