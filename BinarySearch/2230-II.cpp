#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	vector<int> A(N);
	for(auto &i : A)
	{
		cin >> i;
	}
	
	if(N == 1)
	{
		cout << M;
		return 0;
	}
	
	sort(A.begin(), A.end());
	
	int start = 0, end = 1, minus = A[1] - A[0];
	int big = 2000000002;
	
	while(end != N)
	{
		if(big > minus && minus >= M) big = minus;
		if(minus == M)
		{
			cout << M;
			return 0;
		}
		else if(minus > M)
		{
			start++;
			minus = A[end] - A[start];
		}
		else
		{
			end++;
			if(end == N) break;
			minus = A[end] - A[start];
		}
	}
	if(big > minus && minus >= M) big = minus;
	cout << big;
	return 0;
}
