#include <bits/stdc++.h>

using namespace std;

int vertex[801];
int dij[801];

// 0. DIJ ���� (3.2) 
// 1. 1���� V1 �Ǵ� V2�� ���� �� ã��
// 2. V1�Ǵ� V2���� V2E�Ǵ� V1���� ���� �� ã��
// 3. V1, V2���� N���� ���� �� ã�� 

int main(void) {
	fill_n(dij, 801, 200001);
	fill_n(vertex, 801, 999999999);
	
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
	
	vertex[1] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(-vertex[1], 1));
	
	while(!q.empty()) {
		int start_point_vxt = -q.top().first;
		int start_point = q.top().second;
		q.pop();
		for(int i =0; i < dij[start_point].size(); i++) {
			int target = dij[start_point][i].first;
			if(vertex[target] > dij[start_point][i].second + vertex[start_point]) {
				vertex[target] = dij[start_point][i].second + vertex[start_point];
				q.push(make_pair(-vertex[target], dij[start_point][i].first));
			}
		}
	}
	
	for(int i = 1; i <= N; i++) {
		if(vertex[i] < 99999999) {
			cout << vertex[i] << "\n";
		}
		else {
			cout << "INF" << "\n";
		}
	}
	
	return 0;
	
}
