#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	
	unsigned long long river[30][30] = {0, };
	for(int i = 1; i < 30; i++)
	{
		river[1][i] = i;
	}
	
	for(int i = 2; i < 30; i++)
	{
		for(int j = i; j < 30; j++)
		{
			river[i][j] = river[i-1][j-1] + river[i][j-1];
		}
	}
	
	while(T > 0)
	{
		T--;
		int N, M;
		cin >> N >> M;
		
		cout << river[N][M] << endl;
	}
}
