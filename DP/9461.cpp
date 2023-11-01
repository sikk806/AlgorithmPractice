#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	
	unsigned long long answer[101] = {1, 1, 1, 2, 2, 0, };
	
	while(T > 0)
	{
		T--;
		int n;
		cin >> n;
		
		for(int i = 5; i < n; i++)
		{
			answer[i] = answer[i-5] + answer[i - 1];
		}
		
		cout << answer[n-1] << endl;
	}
}
