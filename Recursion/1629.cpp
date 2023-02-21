#include <bits/stdc++.h>

using namespace std;


long long divide(long long A, long long B, long long C) {
	if(B == 1) {
		return A%C;
	}
	long long tmp = divide(A, B/2, C) % C;
	if(B % 2 == 0) {
		return tmp*tmp%C;
	}
	else {
		return tmp*tmp%C*A%C;
	}
}

int main(void) {
	long long A, B, C;
	cin >> A >> B >> C;
	
	cout << divide(A, B, C);
}
