#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	int a[1000001];
	
	a[1] = 1;
	a[2] = 2;
	
	for(int i = 3; i <= N; i++)
	{
		a[i] = a[i-2] + a[i-1];
		a[i] %= 15746;
	}
	cout << a[N];
}
