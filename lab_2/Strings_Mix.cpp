using namespace std;

string strmult(int n, char c)
    {
     string rez = "";
      for (int i = 0; i < n; i++)
        rez += c;
      return rez;  
    }

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2)
  {
    int i;
    int a[26];
    int b[26];
    string rez = "";
    for (i = 0; i < 26; i++)
    {
      a[i] = 0;
      b[i] = 0;
    }
    for (i = 0; i < s1.length(); i++)
      if ((static_cast<int>(s1[i]) - 97 >= 0) && (static_cast<int>(s1[i]) - 97 < 26))
        a[static_cast<int>(s1[i]) - 97]++;
    for (i = 0; i < s2.length(); i++)
      if ((static_cast<int>(s2[i]) - 97 >= 0) && (static_cast<int>(s2[i]) - 97 < 26))
        b[static_cast<int>(s2[i]) - 97]++;
    while (true)
    {
      int max = 1;
      for (i = 0; i < 26; i++)
      {
        if (a[i] > max) 
          max = a[i];
        if (b[i] > max) 
          max = b[i];
      }
      if (max == 1)
        break;       
      for (i = 0; i < 26; i++)
        if ((a[i] == max) && (b[i] != max))
        {
          rez = rez + "/1:" + strmult(max, static_cast<char>(i + 97));  
          a[i] = 0;
          b[i] = 0;
        }
      for (i = 0; i < 26; i++)
        if ((b[i] == max) && (a[i] != max))
        {
          rez = rez + "/2:" + strmult(max, static_cast<char>(i + 97));      
          a[i] = 0;
          b[i] = 0;
        }       
      for (i = 0; i < 26; i++)
        if ((a[i] == max) && (b[i] == max))
        {  
          rez = rez + "/=:" + strmult(max, static_cast<char>(i + 97));
          a[i] = 0;
          b[i] = 0;
        }       
    }
    if (rez.length() > 0)
      rez = rez.substr(1, rez.length() - 1);
    return rez;
  }
};