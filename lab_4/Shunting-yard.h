#include <iostream>
#include <string>

using namespace std;

struct Stack
{
	string data;
	Stack* next;
};

string delete_space(string s);
void push(Stack**, string);
string getFront(Stack*);
string pop(Stack**);
void calc(string);
string getOp(char s);
int getPriority(string op);
string getResult(int b, int a, string op);
void apply(Stack** operators, Stack** output);
