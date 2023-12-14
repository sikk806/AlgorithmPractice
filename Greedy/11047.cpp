#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int answer = 0;
	int N, K;
	cin >> N >> K;
	
	int coins[10];
	
	for(int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}
	
	for(int i = N-1; i >= 0; i--)
	{
		while(coins[i] <= K)
		{
			answer += 1;
			K -= coins[i];
		}
		if(K == 0) break;
	}
	
	cout << answer;
}
