#include <bits/stdc++.h>

using namespace std;

int X[1000000] = {0, };

int main(void)
{
	int N;
	cin >> N;
	
	set<int> press;
	
	int i;
	for(i = 0; i < N; i++)
	{
		cin >> X[i];
		press.insert(X[i]);
	}
	
	set<int>::iterator it;
	i = 0;
	
	unordered_map<int, int> compress;
	
	for(it = press.begin(); it != press.end(); it++)
	{
		compress[*it] = i;
		i++;
	}
	
	for(int i = 0; i < N; i++)
	{
		cout << compress[X[i]] << " ";
	}
	
}
