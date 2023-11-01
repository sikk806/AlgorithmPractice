#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T, k, n;
	cin >> T;
	
	while(T > 0)
	{
		T--;
		cin >> k;
		cin >> n;
		int apt[15][15] = {0, };
		for(int i = 1; i <= n; i++)
		{
			apt[0][i] = i;
		}
		for(int i = 0; i <= k; i++)
		{
			apt[i][1] = 1;
		}
		
		for(int i = 1; i <= k; i++)
		{
			for(int j = 2; j <= n; j++)
			{
				apt[i][j] = apt[i-1][j] + apt[i][j-1];
			}
		}
		
		cout << apt[k][n] << endl;
	}
}
