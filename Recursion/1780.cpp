#include <bits/stdc++.h>

using namespace std;

int paper[2187][2187];
int m_one, zero, one;

void divide(int N, int x, int y) {
	int z = 0;
	int o = 0;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(paper[x + i][y + j] == 0) {
				z++;
			}
			else if(paper[x + i][y + j] == 1) {
				o++;
			}
		}
	}
	
	if(z == N*N) {
		zero++;
	}
	else if(o == N*N) {
		one++;
	}
	else if(z == 0 && o == 0) {
		m_one++;
	}
	else {
		divide(N/3, x, y);
		divide(N/3, x+N/3, y);
		divide(N/3, x+2*N/3, y);
		divide(N/3, x, y+N/3);
		divide(N/3, x+N/3, y+N/3);
		divide(N/3, x+2*+N/3, y+N/3);
		divide(N/3, x, y+2*+N/3);
		divide(N/3, x+N/3, y+2*+N/3);
		divide(N/3, x+2*+N/3, y+2*+N/3);
	}
}

int main(void) {
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	
	m_one = 0;
	zero = 0;
	one = 0;
	
	divide(N, 0, 0);
	
	cout << m_one << '\n' << zero << '\n' << one;
	
}
