#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int from, int sub, int to) {
	if(n == 1) {
		cout << from << " " << to << '\n';
	}
	else {
		hanoi(n-1, from, to, sub);
		cout << from << " " << to << '\n';
		hanoi(n-1, sub, from, to);
	}
} 

int main(void) {
	
	int N;
	cin >> N;
	
	int answer = pow(2, N);
	cout << answer -1 << '\n';
	
	hanoi(N, 1, 2, 3);
	
}
