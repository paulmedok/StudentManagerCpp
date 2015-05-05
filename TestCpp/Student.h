#include "stdafx.h"
#include "stdio.h"
#include <iostream>


using namespace std;

int const NUMOFSUBJECTS = 5;
char* subj[];

struct Subject{
	string title;
	int mark;
};


struct Student{
	string surname;
	string name;
	int age;
	Subject subject[NUMOFSUBJECTS];
};


void EnterNumberOfStudents(int &studnumber);
void EnterStudentsFromCLI(Student* &s, int studnumber);
void PrintStudentsToCLI(Student* &s, int studnumber);
double GetAverangeMark(Student* &s);
void SortStudentsByMark(Student* &s, int studnumber, int subjindex);
Student* Dummy_5_Students();
void SwapStudents(Student* &s1, Student* &s2);
void SwapStudentsPtr(Student* &s1, Student* &s2);
void WriteStudentsToFileTXT(Student* &s, int studnumber);
void WriteStudentsToFileBIN(Student* &s, int studnumber);
void ReadStudentsFromFileBIN(Student* &s, int studnumber);