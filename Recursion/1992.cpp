#include <bits/stdc++.h>

using namespace std;

char video[64][64];
string answer = "";

void quadTree(int N, int x, int y) {
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(video[x + i][y + j] == '1') {
				cnt++;
			}
		}
	}
	if(cnt == N*N) {
		answer += "1";
	}
	else if(cnt == 0) {
		answer += "0";
	}
	else {
		answer += "(";
		quadTree(N/2, x, y);
		quadTree(N/2, x, y+ N/2);
		quadTree(N/2, x + N/2, y);
		quadTree(N/2, x + N/2, y + N/2);
		answer += ")";
	}
}

int main(void) {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> video[i][j];
		}
	}
	quadTree(N, 0, 0);
	
	cout << answer << endl;
}
