#include <bits/stdc++.h>

using namespace std;

int A[500002] = {0, };
int N;

int lower_bound(int idx)
{
	int start = 0, end = N;
	while(start < end)
	{
		int middle = (start+end)/2;
		if(A[middle] < idx) start = middle+1;
		else end = middle;
	}
	
	return start;
}

int upper_bound(int idx)
{
	int start = 0, end = N;
	while(start < end)
	{
		int middle = (start+end)/2;
		if(A[middle] <= idx) start = middle+1;
		else end = middle;
	}
	
	return start;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int M;
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	
	sort(A, A+N);
	
	cin >> M;
	
	int element = 0;
	while(element != M)
	{	
		int idx;
		cin >> idx;
		
		cout << upper_bound(A, A+N, idx)-A << " " << lower_bound(A, A+N, idx)-A << " ";
		cout << upper_bound(idx) << " " << lower_bound(idx) << " ";
		cout << '\n';
		
		element++;
		
	}
}
