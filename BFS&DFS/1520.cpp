#include <bits/stdc++.h>

using namespace std;

int x_p[4] = {0, 1, 0, -1};
int y_p[4] = {1, 0, -1, 0};
int road[500][500];
int memo[500][500];

int M, N;

int dfs(int x, int y) {
	if(x == M-1 && y == N-1) {
		return 1;
	}
	if(memo[x][y] != -1) {
		return memo[x][y];
	}
	memo[x][y] = 0;
	for(int i = 0; i < 4; i++) {
		int tx = x + x_p[i];
		int ty = y + y_p[i];
		if(tx < M && ty < N && tx >= 0 && ty >= 0
		&& road[x][y] > road[tx][ty]) {
			memo[x][y] = memo[x][y] + dfs(tx, ty);
		}
	}
	return memo[x][y];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			cin >> road[i][j];
			memo[i][j] = -1;
		}
	}
	
	cout << dfs(0, 0);
}
