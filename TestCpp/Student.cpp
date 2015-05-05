#include "stdafx.h"
#include "stdio.h"
#include "Student.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <string>

char* subj[NUMOFSUBJECTS] = { "Math", "Programming", "Physics", "Philosophy", "Psychology" };

using namespace std;



void EnterStudentsFromCLI(Student* &s, int studnumber){
			cout << "Enter Information About Students:" << endl;
			int i = 0, j = 0;
			for (i = 0; i < studnumber; i++){
				// Enter Values From CLI
				cout << "Enter Student's " << (i + 1) << " SURNAME:" << endl;
				cin >> s[i].surname;

				cout << "Enter Student's " << (i + 1) << " NAME:" << endl;
				cin >> s[i].name;

				cout << "Enter Student's " << (i + 1) << " AGE:" << endl;
				cin >> (int)s[i].age;

				for (j = 0; j < NUMOFSUBJECTS; j++){
					s[i].subject[j].title = subj[j];
					cout << "Enter Student's " << (i + 1) << " MARK for Subject " << s[i].subject[j].title << ":" << endl;
					cin >> (int)s[i].subject[j].mark;
				}
			}
}

void EnterNumberOfStudents(int &studnumber){
	cout << "Enter Nmber Of Students" << endl;
	cin >> (int)studnumber;
}


void PrintStudentsToCLI(Student* &s, int studnumber){
	cout << "Information About Students:" << endl << endl;
	int i = 0, j = 0;
	Student *stavr;
	for (i = 0; i < studnumber; i++){
		// Enter Values From CLI
		cout << "Student's " << (i + 1) << " SURNAME: " << s[i].surname << endl;
		cout << "Student's " << (i + 1) << " NAME: " << s[i].name << endl;
		cout << "Student's " << (i + 1) << " AGE: " << s[i].age << endl;
		for (j = 0; j < NUMOFSUBJECTS; j++){
			s[i].subject[j].title = subj[j];
			cout << "Student's " << (i + 1) << " MARK for Subject " << s[i].subject[j].title << ":" << s[i].subject[j].mark << endl;
		}
		stavr = &s[i];
		cout << "Students Averange Mark: " << GetAverangeMark(stavr) << endl;
		cout << endl;
	}
}


void WriteStudentsToFileTXT(Student* &s, int studnumber){
	ofstream file;
	file.open("students.txt");
	file.clear();
	file << "Number Of Students:" << studnumber << endl;
	file << "Information About Students:" << endl << endl;
	int i = 0, j = 0;
	Student *stavr;
	for (i = 0; i < studnumber; i++){
		// Enter Values From CLI
		file << "Student's " << (i + 1) << " SURNAME: " << s[i].surname << endl;
		file << "Student's " << (i + 1) << " NAME: " << s[i].name << endl;
		file << "Student's " << (i + 1) << " AGE: " << s[i].age << endl;
		for (j = 0; j < NUMOFSUBJECTS; j++){
			s[i].subject[j].title = subj[j];
			file << "Student's " << (i + 1) << " MARK for Subject " << s[i].subject[j].title << ":" << s[i].subject[j].mark << endl;
		}
		stavr = &s[i];
		file << "Students Averange Mark: " << GetAverangeMark(stavr) << endl;
		file << endl;
	}

	file.close();
}

void WriteStudentsToFileBIN(Student* &s, int studnumber){
	int i = 0;
	FILE *file;
	file = fopen("students.bin", "wb");
	for (i = 0; i < studnumber; i++){
		fseek(file, sizeof(Student)*i, SEEK_SET);
		fwrite((char*)&s[i], sizeof(Student), 1, file);
	}	
	fclose(file);
}

void ReadStudentsFromFileBIN(Student* &s, int studnumber){
	int i = 0;
	ifstream file("students.bin", ios::binary | ios::in);
	if (file.is_open()){
		file.seekg(0);
		for (i = 0; i < studnumber; i++){
			file.seekg(sizeof(Student)* i, file.beg);
			file.get((char*)&s[i], sizeof(Student));
		}
		file.close();
	}
	else{
		cout << "Error while opening file!" << endl;
	}
}

double GetAverangeMark(Student* &s){
	int i = 0;
	double avr = 0.0;
	for (i = 0; i < NUMOFSUBJECTS; i++){
		avr += s->subject[i].mark;
	}
	avr = avr / NUMOFSUBJECTS;

	return avr;
}

void SortStudentsByMark(Student* &s, int studnumber, int subjindex){
	int i = 0, j = 0; //Bouble Sort - the easiest way
	bool flag = false;
	Student *s1, *s2;

	while (!flag){
		flag = true;
		if (subjindex == 0){
			for (i = 0; i < studnumber - 1; i++){
				if (s[i].subject[0].mark > s[i + 1].subject[0].mark){

					s1 = &s[i];
					s2 = &s[i + 1];
					SwapStudents(s1, s2);

					flag = false;
				}
			}
		}
		if (subjindex == 1){
			for (i = 0; i < studnumber - 1; i++){
				if (s[i].subject[1].mark > s[i + 1].subject[1].mark){

					s1 = &s[i];
					s2 = &s[i + 1];
					SwapStudents(s1, s2);

					flag = false;
				}
			}
		}
		if (subjindex == 2){
			for (i = 0; i < studnumber - 1; i++){
				if (s[i].subject[2].mark > s[i + 1].subject[2].mark){

					s1 = &s[i];
					s2 = &s[i + 1];
					SwapStudents(s1, s2);

					flag = false;
				}
			}
		}
		if (subjindex == 3){
			for (i = 0; i < studnumber - 1; i++){
				if (s[i].subject[3].mark > s[i + 1].subject[3].mark){

					s1 = &s[i];
					s2 = &s[i + 1];
					SwapStudents(s1, s2);

					flag = false;
				}
			}
		}
		if (subjindex == 4){
			for (i = 0; i < studnumber - 1; i++){
				if (s[i].subject[4].mark > s[i + 1].subject[4].mark){

					s1 = &s[i];
					s2 = &s[i + 1];
					SwapStudents(s1, s2);

					flag = false;
				}
			}
		
		}
	}
}

void SwapStudents(Student* &s1, Student* &s2){
	int i = 0, j = 0;
	Student tempstudent;
//tempstudent <- s1	
	tempstudent.surname = s1->surname;
	tempstudent.name = s1->name;
	tempstudent.age = s1->age;
	for (i = 0; i < NUMOFSUBJECTS; i++){
		tempstudent.subject[i] = s1->subject[i];
	}

//s1 <- s2
	s1->surname = s2->surname;
	s1->name = s2->name;
	s1->age = s2->age;
	for (i = 0; i < NUMOFSUBJECTS; i++){
		s1->subject[i] = s2->subject[i];
	}

//s2 <- tempstudent
	s2->surname = tempstudent.surname;
	s2->name = tempstudent.name;
	s2->age = tempstudent.age;
	for (i = 0; i < NUMOFSUBJECTS; i++){
		s2->subject[i] = tempstudent.subject[i];
	}
}

void SwapStudentsPtr(Student* &s1, Student* &s2){
	int i = 0, j = 0;
	Student **tempstudent1;
	Student **tempstudent2;
	Student **tempstudent;
	//tempstudent <- s1	
	tempstudent1 = &s1;
	tempstudent2 = &s2;

	tempstudent = tempstudent1;
	tempstudent1 = tempstudent2;
	tempstudent2 = tempstudent;

	s1 = *tempstudent1;
	s2 = *tempstudent2;

	
}

Student* Dummy_5_Students(){
	Student *ds = new Student[5];
	// init subjects
	int i = 0, j = 0;
	for (i = 0; i < 5; i++){ //Dummy students number
		for (j = 0; j < NUMOFSUBJECTS; j++){ // ech students subjects number
			ds[i].subject[j].title = subj[j];
			ds[i].subject[j].mark = rand() % 6;
		}
	}
	//;
	ds[0].surname = "Ivanov";
	ds[0].name = "Ivan";
	ds[0].age = 19;
	//;
	ds[1].surname = "Kirillov";
	ds[1].name = "Kirill";
	ds[1].age = 20;
	//;
	ds[2].surname = "Petrov";
	ds[2].name = "Petr";
	ds[2].age = 18;
	//;
	ds[3].surname = "Zachariy";
	ds[3].name = "Zakhar";
	ds[3].age = 21;
	//;
	ds[4].surname = "Mihailov";
	ds[4].name = "Michail";
	ds[4].age = 17;
	
	return ds;
}