#include<string>
using namespace std;

bool valid_braces(string s)
{
	int i = 0, j;
	char q;
	while (s.length() > 0)
	{
		if ((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))
		{
			if (s[i] == ')')
				q = '(';
			if (s[i] == ']')
				q = '[';
			if (s[i] == '}')
				q = '{';
			j = i - 1;
			while (j >= 0)
			{
				if (s[j] == q)
				{
					s = s.substr(0, j) + s.substr(j + 1, i - j - 1) + s.substr(i + 1, s.size() - i - 1);
					i -= 2;;
					break;
				}
				else if ((s[j] == '{') || (s[j] == '[') || (s[j] == '('))
					return false;
				j--;
			}
		}
		i++;
	}
	if (s.length() == 0)
		return true;
	else
		return false;
}