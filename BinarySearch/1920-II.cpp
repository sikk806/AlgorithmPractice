#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N;
	vector<int> A(N);
	
	for(auto &i : A)
	{
		cin >> i;
	}

	sort(A.begin(), A.end());
	
	cin >> M;
	vector<int> X(M);
	for(auto &i : X)
	{
		cin >> i;
		cout << binary_search(A.begin(), A.end(), i) << '\n';
	}
}
