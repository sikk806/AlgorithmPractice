#include <bits/stdc++.h>

using namespace std;

int main(void)
{	
	vector<int> a = {1, 2, 3};
	
	do
	{
		for(int i = 0; i < 3; i++)
		{
			cout << a[i] << " ";
		}
		cout << '\n';
	}while(next_permutation(a.begin(), a.end()));
}
