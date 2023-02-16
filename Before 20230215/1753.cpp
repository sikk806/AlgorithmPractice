#include <bits/stdc++.h>

using namespace std;

int vertex[20001]; // 정점으로 부터의 길이
int dij[20001];
int INF = 999999;

int main(void) {
	fill_n(dij, 20001, 11);
	fill_n(vertex, 20001, 999999);
	
	vector<vector<pair<int, int>> > dij(20001);
	
	int V, E, K, u, v, w;
	
	cin >> V >> E;
	cin >> K;
	
	for(int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		dij[u].push_back(make_pair(v, w));
	}
	
	vertex[K] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(-vertex[K], K));
	
	while(!q.empty()) {
		int start_point_vxt = -q.top().first;
		int start_point = q.top().second;
		for(int i = 0; i < dij[start_point].size(); i++) {
			int target = dij[start_point][i].first;
			if(vertex[target] > dij[start_point][i].second + vertex[start_point]) {
				vertex[target] = dij[start_point][i].second + vertex[start_point];
				q.push(make_pair(-vertex[target], dij[start_point][i].first));
			}
		}
		q.pop();
	}
	
	for(int i = 1; i <= V; i++) {
		if(vertex[i] < INF) {
			cout << vertex[i] << "\n";
		}
		else {
			cout << "INF" << "\n";
		}
	}
	
	return 0;
}
