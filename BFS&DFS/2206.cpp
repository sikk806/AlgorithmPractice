#include <bits/stdc++.h>

using namespace std;

int x_p[4] = {0, 0, 1, -1};
int y_p[4] = {1, -1, 0, 0};
char maze[1000][1000] = {0, };
int check[1000][1000] = {0, };

int main(void) {
	fill_n(&check[0][0], 1000000, 1000001);
	
	int wall;
	int N, M, x, y;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}
	
	// x, y
	queue<pair<int, int> > q;
	// wall_check : 한번도 안지났으면 0, 부쉈으면 1 
	queue<int> wall_check;
	q.push(make_pair(0, 0));
	wall_check.push(0);
	
	check[0][0] = 1;
	
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		if(x == N-1 && y == M-1) {
			break;
		}
		
		wall = wall_check.front();
		wall_check.pop();
		
		for(int i = 0; i < 4; i++) {
			int tmpX = x + x_p[i];
			int tmpY = y + y_p[i];
			if(tmpX >= 0 && tmpY >= 0 && tmpX < N && tmpY < M) {
				if(check[tmpX][tmpY] > check[x][y] + 1) {
					if(wall == 0) {
						if(maze[tmpX][tmpY] == '0') {
							q.push(make_pair(tmpX, tmpY));
							wall_check.push(0);
							check[tmpX][tmpY] = check[x][y] + 1;
						}
						else {
							q.push(make_pair(tmpX, tmpY));
							wall_check.push(1);
							check[tmpX][tmpY] = check[x][y] + 1;
						}
					}
					else {
						if(maze[tmpX][tmpY] == '0') {
							q.push(make_pair(tmpX, tmpY));
							wall_check.push(1);
							check[tmpX][tmpY] = check[x][y] +1;
						}
					}
				}
			}
		}
	}
	
	if(x == N-1 && y == M-1) {
		cout << check[x][y] << endl;
	}
	else {
		cout << "-1" << endl;
	}
	
	
	return 0;
}
