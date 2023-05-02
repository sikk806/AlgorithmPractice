#include <bits/stdc++.h>

using namespace std;

int x_p[4] = {0, 0, 1, -1};
int y_p[4] = {1, -1, 0, 0};
char maze[1000][1000] = {0, };

// first : length, second : wall_check - 한번도 안지났으면 0, 부쉈으면 1 
pair<int, int> check[1000][1000];

int main(void) {
	fill_n(&check[0][0], 1000000, make_pair(1000001, 0));
	
	int N, M, x, y;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}
	
	// x, y
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	
	check[0][0].first = 1;
	check[0][0].second = 0;
	
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		if(x == N-1 && y == M-1) {
			break;
		} 
		
		for(int i = 0; i < 4; i++) {
			int tmpX = x + x_p[i];
			int tmpY = y + y_p[i];
			if(tmpX >= 0 && tmpY >= 0 && tmpX < N && tmpY < M) {
				if(check[tmpX][tmpY].first > check[x][y].first + 1) {
					if(check[x][y].second == 0) {
						if(maze[tmpX][tmpY] == '0') {
							q.push(make_pair(tmpX, tmpY));
							check[tmpX][tmpY].first = check[x][y].first + 1;
							check[tmpX][tmpY].second = 0;
						}
						else {
							q.push(make_pair(tmpX, tmpY));
							check[tmpX][tmpY].first = check[x][y].first + 1;
							check[tmpX][tmpY].second = 1;
						}
					}
					else {
						if(maze[tmpX][tmpY] == '0') {
							q.push(make_pair(tmpX, tmpY));
							check[tmpX][tmpY].first = check[x][y].first +1;
							check[tmpX][tmpY].second = 1;
						}
					}
				}
				else {
					if(check[x][y].second == 0 && check[tmpX][tmpY].second == 1) {
						if(maze[tmpX][tmpY] == '0') {
							q.push(make_pair(tmpX, tmpY));
							check[tmpX][tmpY].first = check[x][y].first + 1;
							check[tmpX][tmpY].second = 0;
						}
						else {
							q.push(make_pair(tmpX, tmpY));
							check[tmpX][tmpY].first = check[x][y].first + 1;
							check[tmpX][tmpY].second = 1;
						}
					}
				}
			}
		}
	}
	if(x == N-1 && y == M-1) {
		cout << check[x][y].first << endl;
	}
	else {
		cout << "-1" << endl;
	}
	
	
	return 0;
}
