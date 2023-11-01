#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	int price[1001][3] = {0, };
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin >> price[i][j];
		}
	}
	
	int answer[1001][3] = {0, };
	for(int i = 0; i < 3; i++)
	{
		answer[1][i] = price[1][i];
	}
	
	for(int i = 2; i <= N; i++)
	{
		answer[i][0] = min(price[i][0] + answer[i-1][1], price[i][0] + answer[i-1][2]);
		answer[i][1] = min(price[i][1] + answer[i-1][0], price[i][1] + answer[i-1][2]);
		answer[i][2] = min(price[i][2] + answer[i-1][0], price[i][2] + answer[i-1][1]);
	}
	
	int ans = min(answer[N][0], answer[N][1]);
	ans = min(ans, answer[N][2]);
	
	cout << ans;
	
	
}
