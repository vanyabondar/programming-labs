#include "Shunting-yard.h"

void push(Stack** s, string data)
{
	Stack* tmp = new Stack;
	tmp->data = data;
	tmp->next = *s;
	*s = tmp;
}

string getFront(Stack* s)
{
	if (s == nullptr) return '\0';
	return s->data;
}

string pop(Stack** s)
{
	if (*s == nullptr) return "";
	string t = (*s)->data;
	Stack* tmp = (*s)->next;
	delete (*s);
	(*s) = tmp;
	return t;
}

string getOp(char s)
{
	switch (s)
	{
		case '+': 
			return "+";
		case '-':
			return "-";
		case '/':
			return "/";
		case '*':
			return "*";
		case '^':
			return "^";
		default: 
			return "";
	}
}

string delete_space(string s) {
	string rez = "";
	for (int i = 0; i < s.length(); i++)
		if (s[i] != ' ')
			rez += s[i];
	return rez;
}

int getPriority(string op)
{
	if (op == "(")
		return 4;
	if (op == "+" || op == "-")
		return 3;
	if (op == "/" || op == "*")
		return 2;
	if (op == "^")
		return 1;
}

string getResult(int b, int a, string op)
{
	if (op == "+") return to_string(b + a);
	if (op == "-") return to_string(b - a);
	if (op == "*") return to_string(b * a);
	if (op == "/") return to_string(b / a);
	if (op == "^") return to_string((int)pow(b, a));
}

void apply(Stack** operators, Stack** output)
{
	int a = stoi(pop(output));
	int b = stoi(pop(output));
	push(output, getResult(b, a, pop(operators)));
}

void calc(string expr)
{
	Stack* operators = nullptr;
	Stack* output = nullptr;
	if (expr == "")
	{
		getline(cin, expr);
		expr = delete_space(expr);
	}
	int i = 0;
	while (expr[i] != '\0')
	{
		if (expr[i] >= '0' && expr[i] <= '9')
		{
			string num = "";
			while (expr[i] >= '0' && expr[i] <= '9')
			{
				num += expr[i];
				i++;
			}
			push(&output, num);
			i--;
		}
		else if (getOp(expr[i]) != "")
		{
			string op = getOp(expr[i]);
			int p = getPriority(op);
			if (p != 1)
				while (operators != nullptr && p >= getPriority(getFront(operators)))
				{
					apply(&operators, &output);
				}
			push(&operators, op);
		}
		else if (expr[i] == '(')
		{
			push(&operators, "(");
		}
		else if (expr[i] == ')')
		{
			while (getFront(operators) != "(")
			{
				apply(&operators, &output);
			}
			pop(&operators);
		}
		i++;
	}
	while (operators != nullptr)
	{
		apply(&operators, &output);
	}
	cout << "Result: ";
	cout << pop(&output) << endl;
	
}