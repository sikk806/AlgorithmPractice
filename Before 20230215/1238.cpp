#include <bits/stdc++.h>

using namespace std;

int answer[1001];
int vertex[1001];
int dij[1001];
int rev_dij[1001];

void do_dij(int N, int X, vector<vector<pair<int, int>> > dij) {
	fill_n(vertex, 1001, 100001);
	priority_queue<pair<int, int>> q;
	vertex[X] = 0;
	q.push(make_pair(-vertex[X], X));
	while(!q.empty()) {
		int start_point = q.top().second;
		q.pop();
		for(int i = 0; i < dij[start_point].size(); i++) {
			if(vertex[dij[start_point][i].first] > dij[start_point][i].second + vertex[start_point]) {
				vertex[dij[start_point][i].first] = dij[start_point][i].second + vertex[start_point];
				q.push(make_pair(-vertex[dij[start_point][i].first], dij[start_point][i].first));
			}
		}
	}
	for(int i = 1; i <= N; i++) {
		answer[i] += vertex[i];
	}
	answer[X] = 0;
}

int main(void) {
	fill_n(answer, 1001, 0);
	fill_n(dij, 1001, 10001);
	fill_n(rev_dij, 1001, 10001);
	
	int N, M, X, T, a, b;
	cin >> N >> M >> X;
	
	vector<vector<pair<int, int>> > dij(1001);
	vector<vector<pair<int, int>> > rev_dij(1001);
	
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> T;
//		a에서 b로 가는 길이 2개 이상일 경우 
//		for(int j = 0; j < dij[a].size(); j++) {
//			if(dij[a][j].first == b) {
//				if(dij[a][j].second > T) {
//					dij[a][j].second = T;
//				}
//				else {
//					break;
//				}
//			}
//		}
		dij[a].push_back(make_pair(b, T));
		rev_dij[b].push_back(make_pair(a, T));
	}
	do_dij(N, X, rev_dij);
	do_dij(N, X, dij);
	
	int max = 0;
	int max_i = 0;
	for(int i = 1; i <= N; i++) {
		if(max < answer[i]) {
			max = answer[i];
			max_i = i;
		}
	}
	cout << max << endl;
}
