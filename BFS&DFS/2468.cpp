#include <bits/stdc++.h>

using namespace std;

int pos_x[4] = {0, 1, 0, -1};
int pos_y[4] = {1, 0, -1, 0};

int building[100][100];
int check[100][100];

void dfs(int x, int y, int rain, int N) {
	check[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int tmp_x = x + pos_x[i];
		int tmp_y = y + pos_y[i];
		if(tmp_x >= 0 && tmp_x < N && tmp_y >= 0 && tmp_y < N &&
		 check[tmp_x][tmp_y] == 0 && building[tmp_x][tmp_y] > rain) {
			dfs(tmp_x, tmp_y, rain, N);
		}
	}
}

int main(void) {
	int N;
	cin >> N;
	
	int highest = 0;
	int lowest = 999;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> building[i][j];
			if(building[i][j] > highest) {
				highest = building[i][j];
			}
			if(building[i][j] < lowest) {
				lowest = building[i][j];
			}
		}
	}
	
	int answer = 1;
	
	for(int c = lowest; c < highest; c++) {
		int cnt = 0;
		fill(&check[0][0], &check[99][100], 0);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(check[i][j] == 0 && building[i][j] > c) {
					cnt++;
					dfs(i, j, c, N);
				}
			}
		}
		
		if(answer < cnt) {
			answer = cnt;
		}
	}
	
	cout << answer;
}
