#include <iostream>
#include <stdlib.h>

using namespace std;

int N;
int answer;

int check(int chess[15][15], int x, int y) {
	int tmp_X = x-1;
	int min = y-x;
	int sum = x+y;
	
	while(tmp_X >= 0) {
		if(min + tmp_X >= 0) {
			if(chess[tmp_X][min + tmp_X] == 1) return 0;
		}
		if(sum - tmp_X < N) {
			if(chess[tmp_X][sum - tmp_X] == 1) return 0;
		}
		if(chess[tmp_X][y] == 1) return 0;
		
		tmp_X--;
	}
	
	return 1;
}

void bf(int cnt, int chess[15][15], int x) {
	if(cnt == N) {
		answer++;
		return;
	}
	for(int j = 0; j < N; j++) {
		int ck = check(chess, x, j);
		if(check(chess, x, j) == 1) {
			chess[x][j] = 1;
			bf(cnt+1, chess, x+1);
			chess[x][j] = 0;
		}
	}
}


int main(void) {
	int chess[15][15] = {0, };
	answer = 0;
	
	cin >> N;
	
	int cnt = 0;
	bf(cnt, chess, 0);
	
	cout << answer << endl;
	
}
