#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int K;
	cin >> K;
	pair<int, int> way_check[6];
	
	int way, length;
	int max_H = 0;
	int max_V = 0;
	int answer = 0;
	for(int i = 0; i < 6; i++) {
		cin >> way >> length;
		way_check[i] = make_pair(way, length);
		if(way == 1 || way == 2) {
			if(length > max_H) {
				max_H = length;
			}
		}
		else if(way == 3 || way == 4) {
			if(length > max_V) {
				max_V = length;
			}
		}
	}
	for(int i = 0; i < 4; i++) {
		if(way_check[i].first == way_check[i+2].first) {
			answer = max_H * max_V - way_check[i+1].second * way_check[i+2].second;
			break;
		}
	}
	if(way_check[0].first == way_check[2].first && way_check[1].first == way_check[5].first) {
		answer = max_H * max_V - way_check[0].second * way_check[1].second;
	}
	else if(way_check[0].first == way_check[4].first && way_check[1].first == way_check[5].first) {
		answer = max_H * max_V - way_check[0].second * way_check[5].second;
	}
	
	cout << answer * K << endl;
}
