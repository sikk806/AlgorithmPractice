#include <bits/stdc++.h>

using namespace std;


int bag[101][100001] = {0, };
pair<int, int> object[101];

int main(void) {
	
	int N, K, W, V;
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++) {
		cin >> W >> V;
		object[i] = make_pair(W, V);
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= K; j++) {
			if(object[i].first > j)
				bag[i][j] = bag[i-1][j];
			else {
				bag[i][j] = max(bag[i-1][j], bag[i-1][j-object[i].first] + object[i].second);
			}
		}
	}
	
	cout << bag[N][K] << endl;
	
	return 0;
}	
