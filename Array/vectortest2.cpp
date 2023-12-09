#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	vector<int> v2(3, 5);
	
	v2.pop_back();
	
	for(int e : v2)
	{
		e = 0;
	}
	cout << v2[0] << endl;
	cout << endl;
	
	for(int &e : v2)
	{
		e = 0;
		cout << e << " ";
	}
	cout << v2[0] << endl;
}
