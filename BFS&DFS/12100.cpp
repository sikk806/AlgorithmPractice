#include <bits/stdc++.h>

using namespace std;

int N;
int max_no;

void play(int board[][20], cnt) {
	if(cnt == 5) {
		return;
	}
	playUp(board, cnt);
}

void playUp(int board[][20]) {
	// 1. 위로
	int i = 0, j = 0;
	int check = board[i][j];
	while(check == 0 && i < N) {
		i++;
		check = board[i][j];
	}
	while(j != N) {
		if(i >= N) {
			i = 0;
			j++;
			check = board[i][j];
			while(check == 0 && i < N) {
				i++;
				check = board[i][j];
			}
		}
		
		for(int k = 1; i+k < N; k++) {
			if(check == 0) {
				check = board[i+k][j];
			}
			else {
				if(check == board[i+k][j]) {
					board[i][j] *= 2;
					board[i+k][j] = 0;
					check = 0;
					i = i+k;
					k = 1;
				}
				else {
					check = board[i+k][j];
				}
			}
		}
		
	}
}

int main(void) {
	// 메모리 초과 : vector로 바꿀것. 
	int board[20][20] = {0, };
	
	cin >> N;
	max_no = 0;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> board[i][j];
			if(max_no < board[i][j])
				max_no = board[i][j];
		}
	}
	
	play(board);
}
