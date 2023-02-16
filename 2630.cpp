#include <bits/stdc++.h>

using namespace std;

int square[128][128] = {0, };
int color[128][128];

int main(void) {
	fill(&color[0][0], &color[128][128], -1);
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> square[i][j];
		}
	}
	
	
}
