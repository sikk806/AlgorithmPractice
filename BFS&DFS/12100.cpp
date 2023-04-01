#include <bits/stdc++.h>

using namespace std;

int N;
int max_no;

void play(int board[][20], int cnt);

// 1. 위로 
void playUp(int board[][20], int cnt) {
	for(int j = 0; j < N; j++) {
		int position_i = 0;
		int i = 0;
		while(1) {
			if(board[i][j] == 0) {
				i++;
				if(i >= N) break;
				continue;
			}
			board[position_i][j] = board[i][j];
			i++;
			if(i >= N) {
				position_i++;
				break;
			}			
			while(i < N && board[i][j] == 0) {
				i++;
			}
			if(i == N) {
				position_i++;
				break;
			}
			else {
				if(board[i][j] == board[position_i][j]) {
					board[position_i][j] *= 2;
					if(max_no < board[position_i][j]) max_no = board[position_i][j];
					board[i][j] = 0;
					position_i++;
				}
				else {
					position_i++;
				}
			}
		}
		while(position_i < N) {
			board[position_i][j] = 0;
			position_i++;
		}
	}
//	for(int a = 0; a < N; a++) {
//		for(int b = 0; b < N; b++) {
//			cout << board[a][b] << " ";
//		}
//		cout << endl;
//	}
	play(board, cnt+1);
}

// 2. 아래로 
void playDown(int board[][20], int cnt) {
	for(int j = 0; j < N; j++) {
		int position_i = N-1;
		int i = N-1;
		while(1) {
			if(i < 0) break;
			if(board[i][j] == 0) {
				i--;
				continue;
			}
			board[position_i][j] = board[i][j];
			i--;
			if(i < 0) {
				position_i--;
				break;
			}			
			while(i >= 0 && board[i][j] == 0) {
				i--;
			}
			if(i == -1) {
				position_i--;
				break;
			}
			else {
				if(board[i][j] == board[position_i][j]) {
					board[position_i][j] *= 2;
					if(max_no < board[position_i][j]) max_no = board[position_i][j];
					board[i][j] = 0;
					position_i--;
				}
				else {
					position_i--;
				}
			}
		}
		
		while(position_i >= 0) {
			board[position_i][j] = 0;
			position_i--;
		}
	}
	play(board, cnt+1);
	
}

// 3. 왼쪽으로
void playLeft(int board[][20], int cnt) {
	for(int i = 0; i < N; i++) {
		int position_j = 0;
		int j = 0;
		while(1) {
			if(board[i][j] == 0) {
				j++;
				if(j >= N) break;
				continue;
			}
			board[i][position_j] = board[i][j];
			j++;
			if(j >= N) {
				position_j++;
				break;
			}			
			while(j < N && board[i][j] == 0) {
				j++;
			}
			if(j == N) {
				position_j++;
				break;
			}
			else {
				if(board[i][j] == board[i][position_j]) {
					board[i][position_j] *= 2;
					if(max_no < board[i][position_j]) max_no = board[i][position_j];
					board[i][j] = 0;
					position_j++;
				}
				else {
					position_j++;
				}
			}
		}
		while(position_j < N) {
			board[i][position_j] = 0;
			position_j++;
		}
	}
	play(board, cnt+1);
}

// 4. 오른쪽으로 
void playRight(int board[][20], int cnt) {
	for(int i = 0; i < N; i++) {
		int position_j = N-1;
		int j = N-1;
		while(1) {
			if(j < 0) break;
			if(board[i][j] == 0) {
				j--;
				continue;
			}
			board[i][position_j] = board[i][j];
			j--;
			if(j < 0) {
				position_j--;
				break;
			}			
			while(j >= 0 && board[i][j] == 0) {
				j--;
			}
			if(j == -1) {
				position_j--;
				break;
			}
			else {
				if(board[i][j] == board[i][position_j]) {
					board[i][position_j] *= 2;
					if(max_no < board[i][position_j]) max_no = board[i][position_j];
					board[i][j] = 0;
					position_j--;
				}
				else {
					position_j--;
				}
			}
		}
		
		while(position_j >= 0) {
			board[i][position_j] = 0;
			position_j--;
		}
	}
	play(board, cnt+1);
	
}

void play(int board[][20], int cnt) {
	if(cnt == 5) {
			for(int a = 0; a < N; a++) {
		for(int b = 0; b < N; b++) {
			cout << board[a][b] << " ";
		}
		cout << endl;
	}
		return;
	}
	playUp(board, cnt);
	playDown(board, cnt);
	playLeft(board, cnt);
	playRight(board, cnt);
}

int main(void) {
	int board[20][20] = {0, };
	
	cin >> N;
	max_no = 2;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> board[i][j];
			if(max_no < board[i][j])
				max_no = board[i][j];
		}
	}
	play(board, 1);
	
	cout << max_no;
}
