#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	unsigned long long answer[91] = {0, 1, 0,};
	
	for(int i = 2; i < 91; i++)
	{
		answer[i] = answer[i-1] + answer[i-2];
	}
	
	cout << answer[n];
}
