#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int cups[4] = {0, 1, 2, 3};
	int N, change_1, change_2;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> change_1 >> change_2;
		int temp = cups[change_1];
		cups[change_1] = cups[change_2];
		cups[change_2] = temp;
	}
	
	for(int i = 1; i < 4; i++) {
		if(cups[i] == 1) {
			cout << i;
			break;
		}
	}
	
	return 0;
}
