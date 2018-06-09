#include<vector>
using namespace std;
vector<int> xbonacci(vector<int> a, int n)
{
	int sum;
	int size = a.size();
  while (a.size() > n) 
    a.pop_back();
	for (int i = size; i < n; i++) {
		sum = 0;
		for (int j = i - 1; j >= i - size; j--) {
			sum += a[j];
		}
		a.insert(a.end(), sum);
	}
	return a;
}