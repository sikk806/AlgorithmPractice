#include <bits/stdc++.h>

using namespace std;

int N;
int x_p[4] = {0, 0, 1, -1};
int y_p[4] = {1, -1, 0, 0};
int room[50][50] = {0, };
int check[50][50] = {0, };

void bfs() {
	queue<pair<int, int> > q;
	int x, y;
	q.push(make_pair(0, 0));
	check[0][0] = 0;
	
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int xp = x + x_p[i];
			int yp = y + y_p[i];
			if(xp < N && xp >= 0 && yp < N && yp >= 0 ) {
				if(room[xp][yp] == 1) {
					if(check[xp][yp] > check[x][y]) {
						check[xp][yp] = check[x][y];
						q.push(make_pair(xp, yp));
					}
				}
				else {
					if(check[xp][yp] > check[x][y] + 1) {
						check[xp][yp] = check[x][y]+1;
						q.push(make_pair(xp, yp));
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> N;
	char c;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> c;
			room[i][j] = c - '0';
			check[i][j] = 99999999;
		}
	}
	
	bfs();
	
	cout << check[N-1][N-1];
}
