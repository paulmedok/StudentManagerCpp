// TestCpp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include "Student.h"
#include <crtdbg.h>
#include <iostream>
#include <stdlib.h>
//#include "Subjects.h"


//
using namespace std;

int STUDNUMBER = 0;
// subj[];

int _tmain(int argc, _TCHAR* argv[])
{
	
	/*
	EnterNumberOfStudents(STUDNUMBER);
	Student *s = new Student[STUDNUMBER];

	EnterStudentsFromCLI(s, STUDNUMBER);
	PrintStudentsToCLI(s, STUDNUMBER);
	SortStudentsByMark(s, STUDNUMBER, 4);
	PrintStudentsToCLI(s, STUDNUMBER);
	WriteStudentsToFileTXT(s, STUDNUMBER);
	*/
	
	Student *ds = Dummy_5_Students();
	
	PrintStudentsToCLI(ds, 5);
	SortStudentsByMark(ds, 5, 0);
	
	PrintStudentsToCLI(ds, 5);

	/*WriteStudentsToFileTXT(ds, 5);
	
	PrintStudentsToCLI(ds, 5);
	WriteStudentsToFileBIN(ds, 5);

	PrintStudentsToCLI(ds, 5);
	ReadStudentsFromFileBIN(ds, 5);

	PrintStudentsToCLI(ds, 5);*/
	
	delete [] ds;

	if (_CrtDumpMemoryLeaks())
		cout << "MemoryLeaks!!!" << endl;
	else
		cout << "Memory OK " << endl;

	getchar();
	return 0;
}


