#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	long long answer[101][10] = {0, };
	
	answer[1][0] = 0;
	
	for(int i = 1; i < 10; i++)
	{
		answer[1][i] = 1;
	}
	
	for(int i = 2; i < 101; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(j == 0)
			{
				answer[i][j] = answer[i-1][1] % 1000000000;
			}
			else if(j == 9)
			{
				answer[i][j] = answer[i-1][8] % 1000000000;
			}
			else
			{
				answer[i][j] = (answer[i-1][j+1] % 1000000000 + answer[i-1][j-1] % 1000000000) % 1000000000;
			}
		}
	}
	
	long long sum = 0;
	for(int i = 0; i < 10; i++)
	{
		sum += (answer[n][i] % 1000000000);
	}
	
	cout << sum;
	
}
