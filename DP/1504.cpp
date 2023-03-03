#include <bits/stdc++.h>

using namespace std;

int vertex_1[801]; // v1먼저 가는 경우 
int vertex_2[801]; // v2먼저 가는 경우 
int dij[801];

// 0. DIJ 구현 (3.2) 
// 1. 1에서 V1 또는 V2로 가는 길 찾기
// 2. V1또는 V2에서 V2E또는 V1으로 가는 길 찾기
// 3. V1, V2에서 N으로 가는 길 찾기 
void dijkstra(int start, int end, int vertex[], vector<vector<pair<int, int>> > &dijk) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(-vertex[start], start));
	
	if(vertex[start] == 999999999) {
		return;
	}
	
	while(!q.empty()) {
		int start_point_vxt = -q.top().first;
		int start_point = q.top().second;
		q.pop();
		if(start_point == end) {
			return;
		}
		for(int i =0; i < dijk[start_point].size(); i++) {
			int target = dijk[start_point][i].first;
			if(vertex[target] > dijk[start_point][i].second + vertex[start_point]) {
				vertex[target] = dijk[start_point][i].second + vertex[start_point];
				q.push(make_pair(-vertex[target], dijk[start_point][i].first));
			}
		}
	}
}

int main(void) {
	int answer = 999999999;
	fill_n(dij, 801, 200001);
	fill_n(vertex_1, 801, 999999999);
	fill_n(vertex_2, 801, 999999999);
	
	vector<vector<pair<int, int>> > dij(801);
	
	int N, E;
	cin >> N >> E;
	
	int a, b, c;
	for(int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		dij[a].push_back(make_pair(b, c));
		dij[b].push_back(make_pair(a, c));
	}
	
	int v1, v2;
	cin >> v1 >> v2;
	
	int reset_v1 = 0;
	int reset_v2 = 0;
	
	vertex_1[1] = reset_v1;
	vertex_2[1] = reset_v2;
	
	dijkstra(1, v1, vertex_1, dij);
	dijkstra(1, v2, vertex_2, dij);
	
	reset_v1 = vertex_1[v1];
	reset_v2 = vertex_2[v2];
	
	fill_n(vertex_1, N+1, 999999999);
	fill_n(vertex_2, N+1, 999999999);
	
	vertex_1[v1] = reset_v1;
	vertex_2[v2] = reset_v2;
	
	dijkstra(v1, v2, vertex_1, dij);
	dijkstra(v2, v1, vertex_2, dij);
	
	reset_v1 = vertex_1[v2];
	reset_v2 = vertex_2[v1];
	
	fill_n(vertex_1, N+1, 999999999);
	fill_n(vertex_2, N+1, 999999999);
	
	vertex_1[v2] = reset_v1;
	vertex_2[v1] = reset_v2;
	
	dijkstra(v2, N, vertex_1, dij);
	dijkstra(v1, N, vertex_2, dij);
	
	if(vertex_1[N] > vertex_2[N]) {
		answer = vertex_2[N];
	}
	else {
		answer = vertex_1[N];
	}
	
	if(answer == 999999999) {
		cout << "-1" << endl;
	}
	else {
		cout << answer << endl;
	}
	
	return 0;
	
}
