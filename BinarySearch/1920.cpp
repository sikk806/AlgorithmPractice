#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N;
	vector<int> A(N);
	
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	
	sort(A.begin(), A.end());
	
	cin >> M;
	vector<int> X(M);
	for(int i = 0; i < M; i++)
	{
		cin >> X[i];
	}
	int element = 0;
	while(element != M)
	{
		int start = 0;
		int end = N-1;
		int middle = (start+end)/2;
		
		
		while(start < end)
		{
			if(A[middle] == X[element])
			{
				cout << "1" << '\n';
				break;
			}
			else
			{
				if(A[middle] > X[element])
				{
					end = middle-1;
					middle = (start+end)/2;
				}
				else
				{
					start = middle+1;
					middle = (start+end)/2;
				}
			}
		}
		if(start >= end)
		{
			if(A[middle] == X[element]) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		element++;
		
	}
}
