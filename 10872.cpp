#include <bits/stdc++.h>

using namespace std;

int doFactorial(int N) {
	if(N > 1) {
		N *= doFactorial(N-1);
	}
    return N;
}

int main(void) {
	int N;
	cin >> N;
	
	if(N == 0) {
		cout << "1";
	}
	else {
		int answer = doFactorial(N);
		cout << answer;
	}
}
