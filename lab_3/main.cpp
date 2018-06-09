#include "students.h"

int main()
{
	setlocale(LC_CTYPE, "ukr");
	int amount = 0;
	//amount - кількість бюджетників
	student* students = getPointAverage(&amount);
	createSchList(students, amount);
	
	system("pause");
	return 0;
}