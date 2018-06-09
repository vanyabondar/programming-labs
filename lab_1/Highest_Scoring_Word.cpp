#include <string>
using namespace std;
string highestScoringWord(const string &s)
{
  string str = s + " ";
  int n, i, sum, maxk, kil;
  //str += " ";
  int *a = new int[str.length()];
  sum = 0;
  kil = 0;
  for (i = 0; i < str.length(); i++) 
  { 
    if (str[i] == ' ')
    {
      a[i - kil] = sum;
      sum = 0;
      kil = 0;
    }
    else
    {
      sum += (static_cast<int>(str[i]) - 96);
      kil++;
    }
    a[i] = 0;
  }
  string rez = "";
  maxk = a[0];
  for (i = 1; i < str.length(); i++)
    maxk = max(maxk, a[i]);
  for (i = 0; i < str.length(); i++)
    if (a[i] == maxk)
    {
      while (str[i] != ' ')
      {
        rez += str[i];
        i++;
      }
      break;
    }
  
  delete [] a;    
  return rez;
}