#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int get_int(char ch)
{
	int tmp = (int)ch;
	if (tmp < 0) tmp += 256;
	return tmp;
}
void update_counter(int* counter, int* lth)
{
	if (*counter == (int)pow(2, *lth - 1))
	{
		(*lth)++;
		*counter = 0;
	}
	(*counter)++;
}
string cut_byte(string *str)
{
	string tmp = (*str).substr(0, 8);
	(*str).erase(0, 8);
	return tmp;
}
string to_bin(int val, int lth)
{
	if (lth == 0) return "";
	string tmp = "00000000";
	while (tmp.size() < lth) tmp += tmp;
	int i = lth - 1;
	while (val > 0)
	{
		if (val % 2) tmp[i] = '1';
		else tmp[i] = '0';
		val /= 2;
		i--;
	}
	return tmp.substr(0, lth);
}
int to_ten(string bin)
{
	string tmp;
	int val = 0;
	for (int i = 0; i <= bin.size(); i++)
	{
		if (bin[i] != '0')
			val += (int)pow(2, (int)bin.size() - i - 1);
	}
	return val;
}
void compress(char out[], char in[])
{
	ofstream a;
	ifstream f;
	f.open(in, ios::binary);
	a.open(out, ios::binary);
	map<string, int> dict = { {"", 0} };
	char ch;
	string sub;
	string bin;
	int lth = 0;
	int counter = 0;
	a << in << "\r\n";
	while (f.get(ch))
	{
		sub += ch;
		if (!dict[sub])
		{
			dict[sub] = dict.size()-1;
			string sym = to_bin(get_int(ch), 8);
			sub.pop_back();
			bin += to_bin((dict[sub]), lth) + sym;

			while (bin.size() > 8)
				a << (char)to_ten(cut_byte(&bin));
			sub.clear();
			update_counter(&counter, &lth);
		}
	}
	if (sub != "")
		bin += to_bin(dict[sub], lth);
	while (bin.size() > 8)
		a << (char)to_ten(cut_byte(&bin));
	int sz = bin.size();
	a << (char)to_ten(bin) << sz;
	f.close();
	a.close();
	remove(in);
}

void decompress(char out[])
{
	ofstream t;
	ifstream a;
	a.open(out, ios::binary);
	string name;
	int pos = 0;
	char ch;
	while (a.get(ch))
	{
		if (a.peek() == '\n')
		{
			pos = (int)a.tellg() + 1;
			break;
		}
		name += ch;
	}
	t.open(name, ios::binary);
	vector<string> dict = { "" };
	int counter = 0;
	int lth = 0;
	string bin;
	a.seekg(0);
	a.seekg(-1, a.end);
	a.get(ch);
	int val = ch - '0';
	int last = (int)(a.tellg()) - 1;
	a.seekg(pos);
	while (a.get(ch))
	{
		if ((int)a.tellg() != last)
		{
			bin += to_bin(get_int(ch), 8);
		}
		else
		{
			bin += to_bin(get_int(ch), 8).erase(0, 8 - val);
			break;
		}
		if (bin.size() >= 8 + lth)
		{
			string num = bin.substr(0, lth);
			bin.erase(0, lth);
			string sym = cut_byte(&bin);
			string res = dict[to_ten(num)] + (char)to_ten(sym);
			dict.push_back(res);
			t << res;
			update_counter(&counter, &lth);
		}
	}
	if (bin.size() >= 8 + lth)
	{
		string num = bin.substr(0, lth);
		bin.erase(0, lth);
		string sym = cut_byte(&bin);
		string res = dict[to_ten(num)] + (char)to_ten(sym);
		dict.push_back(res);
		t << res;
	}
	if (bin != "")
		t << dict[to_ten(bin)];
	a.close();
	t.close();
	remove(out);
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "not enough args" << endl;
		return 0;
	}
	if (!strcmp(argv[1], "--compress")) compress(argv[2], argv[3]);
	else if (!strcmp(argv[1],"--decompress")) decompress(argv[2]);
	else cout << "unknown command" << endl;
	return 0;
}