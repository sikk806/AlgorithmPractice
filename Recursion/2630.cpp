#include <bits/stdc++.h>

using namespace std;

int color[128][128];
int blue = 0;
int white = 0;

void answer(int N, int x, int y) {
	int cnt = 0;
	// cnt == N * N 이면 Blue, cnt == 0 이면 White, 이도 저도 아니면 재귀
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(color[x + i][y + j] == 1) {
				cnt++;
			}
		}
	}
	if(cnt == N * N) {
		blue++;
	}
	else if(cnt == 0) {
		white++;
	}
	else {
		answer(N/2, x, y);
		answer(N/2, x + N/2, y);
		answer(N/2, x, y + N/2);
		answer(N/2, x + N/2, y + N/2);
	}
}

int main(void) {
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> color[i][j];
		}
	}
	
	answer(N, 0, 0);
	
	cout << white << '\n' << blue << '\n';
}
