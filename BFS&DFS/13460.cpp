#include <bits/stdc++.h>

using namespace std;

int R_X, R_Y;
int B_X, B_Y;
int O_X, O_Y;

int dfs(char board[][10], int cnt) {
	// 1. Right Side
	
}

int main(void) {
	char board[10][10] = {0, };
	int N, M, answer = 0;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
			if(board[i][j] == '.') continue;
			if(board[i][j] == 'R') {
				R_X = i;
				R_Y = j;
			}
			if(board[i][j] == 'B') {
				B_X = i;
				B_Y = j;
			}
			if(board[i][j] == 'O') {
				O_X = i;
				O_Y = j;
			}
		}
	}
	answer = dfs(board, 0);
	
}
