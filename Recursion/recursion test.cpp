#include <bits/stdc++.h>

using namespace std;

int fibo(int N)
{
	if(N == 0) return 0;
	return N + fibo(N-1);
}

int main(void)
{
	int N;
	cin >> N;
	
	int answer = fibo(N);
	cout << answer << endl;
}
