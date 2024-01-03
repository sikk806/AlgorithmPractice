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
	
	sort(A.begin(), A.end());
	
	int lowest = 2000000001;
	
	for(auto i : A)
	{
		int LB = lower_bound(A.begin(), A.end(), i+M) - A.begin();
		if(lowest > A[LB] - i
		&& LB != N)
		{
			lowest = A[LB] - i;
		}
	}
	
	cout << lowest;
}
