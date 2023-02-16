#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int check[51][51];
int cab[51][51];

void cabbage(int x, int y) {
	int pos_x = x;
	int pos_y = y;
	queue<pair<int, int> > position;
	
	position.push(make_pair(pos_x, pos_y));
	check[pos_x][pos_y] = 1;
	
	while(!position.empty()) {
		pos_x = position.front().first;
		pos_y = position.front().second;
		for(int i = 0; i < 4; i++) {
			if(cab[pos_x + dx[i]][pos_y + dy[i]] == 1 &&
			check[pos_x + dx[i]][pos_y + dy[i]] == 0 &&
			pos_x+dx[i] > -1 && pos_x+dx[i] < 51 &&
			pos_y+dy[i] > -1 && pos_y+dy[i] < 51) {
				position.push(make_pair(pos_x+dx[i], pos_y+dy[i]));
				check[pos_x + dx[i]][pos_y + dy[i]] = 1;
			}
		}
		position.pop();
	}
}

int main(void) {
	int T; // testCase
	int M, N, K; //width, height, cabbage
	int X, Y; //position of cabbage
	int cnt = 0;
	vector<int> answer;
	
	cin >> T;
	for(int i = 0; i < T; i++) {
		memset(check, 0, sizeof(check));
		memset(cab, 0, sizeof(cab));
		
		cin >> M >> N >> K;
		for(int j = 0; j < K; j++) {
			cin >> X >> Y;
			cab[X][Y] = 1;
		}
		
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < N; j++) {
				if(check[i][j] == 0 && cab[i][j] == 1) {
					cabbage(i, j);
					cnt++;
				}
			}
		}
		answer.push_back(cnt);
		cnt = 0;
	}
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}
