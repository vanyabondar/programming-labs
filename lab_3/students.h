#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct student {
	string name;
	double mark;
};

void getmark(student*, int*, string*);
void sort(student*, int);
student* getPointAverage(int*);
void createSchList(student*, int);

#endif
