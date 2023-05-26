#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int N;
	int door_x, door_y;
	cin >> N;
	char map[50][50] = {0, };
	// 0 : not arrive, 1 : arrive, 2 : mirror setting
	int check[50][50] = {0, };
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
			if(map[i][j] == '#') {
				door_x = i;
				door_y = j;
			}
		}
	}
	
	queue<pair<int, int> > mirror;
	mirror.push(make_pair(door_x, door_y));
	check[door_x][door_y] = 1;
	int q_size = mirror.size();
	int cnt = 0;
	while(!mirror.empty()) {
		if(q_size == 0) {
			q_size = mirror.size();
			cnt++;
		}
		int pos_x = mirror.front().first;
		int pos_y = mirror.front().second;
		mirror.pop();
		q_size -= 1;
		
		for(int j = 1; j < N; j++) {
			if(pos_x+j >= N) break;
			if(map[pos_x+j][pos_y] == '*' || check[pos_x+j][pos_y] != 0) {
				break;
			}
			else if(map[pos_x+j][pos_y] == '!') {
				check[pos_x+j][pos_y] = 2;
				mirror.push(make_pair(pos_x+j, pos_y));
			}
			else if(map[pos_x+j][pos_y] == '#') {
				cout << cnt << endl;
				return 0;
			}
		}
		for(int j = 1; j < N; j++) {
			if(pos_x-j < 0) break;
			if(map[pos_x-j][pos_y] == '*' || check[pos_x-j][pos_y] != 0) {
				break;
			}
			else if(map[pos_x-j][pos_y] == '!') {
				check[pos_x-j][pos_y] = 2;
				mirror.push(make_pair(pos_x-j, pos_y));
			}
			else if(map[pos_x-j][pos_y] == '#') {
				cout << cnt << endl;
				return 0;
			}
		}
		for(int j = 1; j < N; j++) {
			if(pos_y+j >= N) break;
			if(map[pos_x][pos_y+j] == '*' || check[pos_x][pos_y+j] != 0) {
				break;
			}
			else if(map[pos_x][pos_y+j] == '!') {
				check[pos_x][pos_y+j] = 2;
				mirror.push(make_pair(pos_x, pos_y+j));
			}
			else if(map[pos_x][pos_y+j] == '#') {
				cout << cnt << endl;
				return 0;
			}
		}
		for(int j = 1; j < N; j++) {
			if(pos_y-j < 0) break;
			if(map[pos_x][pos_y-j] == '*' || check[pos_x][pos_y-j] != 0) {
				break;
			}
			else if(map[pos_x][pos_y-j] == '!') {
				check[pos_x][pos_y-j] = 2;
				mirror.push(make_pair(pos_x, pos_y-j));
			}
			else if(map[pos_x][pos_y-j] == '#') {
				cout << cnt << endl;
				return 0;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
