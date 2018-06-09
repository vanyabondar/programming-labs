// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

void read(char* str, int  &length)
{
	char x = ' ';
	while (x != '\n')
	{
		cin.get(x);
		//cin >> x;
		if ((static_cast<int>(x) > 96) && (static_cast<int>(x) < 121))
		{
			str[length++] = x;
		}
	}
	return;
}
int main()
{
	char arr[26][26];
	int i, j;
	cout << "Matrix:" << endl;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 26; j++)
		{
			arr[i][j] = static_cast<char>(97 + (i + j) % 26);
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	char str[255], key[255];
	int strLength = 0;
	int keyLength = 0;
	cout << "Input sentense:" << endl;
	read(str, strLength);
	cout << "Input key:" << endl;
	read(key, keyLength);


	char *keys = new char[strLength];
	//char keys[str.length()];
	int len = 0;
	while (len < strLength)
	{
		keys[len] = key[len % keyLength];
		len++;
	}

	cout << "Encryted sentense:" << endl;
	for (i = 0; i < strLength; i++)
	{
		cout << arr[(static_cast<int>(str[i])) - 97][(static_cast<int>(keys[i])) - 97];
	}
	cout << endl;
	system("pause");
	delete[] keys;
	return 0;
}
