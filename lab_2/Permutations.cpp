#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[26];
int len;
vector<string> rez{};

void find(string str)
{
  if (str.length() == len)
  {
    rez.push_back(str);
    return;
  }
  int b[26];
  int i;
  for (i = 0; i < 26; i++)
    b[i] = a[i];
  for (i = 0; i < str.length(); i++)
    b[static_cast<int>(str[i]) - 97]--;
  for (i = 0; i < 26; i++)
    if (b[i] > 0)
      find(str + static_cast<char>(i + 97));
  return;
}  

vector<string> permutations(string s) {
  rez.clear();
  len = s.length();
  int i;
  for (i = 0; i < 26; i++)
    a[i] = 0;
  for (i = 0; i < s.length(); i++)
    a[static_cast<int>(s[i]) - 97]++;
  find("");
  return rez;
}