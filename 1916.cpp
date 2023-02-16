#include <bits/stdc++.h>

using namespace std;

int cost[1001];
int dij[1001];
bool flag = false;

int main(void) {
	fill_n(cost, 1001, 100000001);
	fill_n(dij, 1001, 100001);
	
	// dij : arrive point, cost
	vector<vector<pair<int, int>> > dij(1001);
	
	int N, M, start, end, a, b, w;
	cin >> N;
	cin >> M;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		for(int j = 0; j < dij[a].size(); j++) {
			if(dij[a][j].first == b && dij[a][j].second > w) {
				dij[a][j].second = w;
				break;
			}
		}
		dij[a].push_back(make_pair(b, w));
	}
	cin >> start >> end;
	
	cost[start] = 0;
	// Queue : -cost, vertex_No
	priority_queue<pair<int, int> > q;
	q.push(make_pair(-cost[start], start));
		
	while(!q.empty()) {
		int start_point_cost = -q.top().first;
		int start_point = q.top().second;
		q.pop();
		if(start_point == end) {
			cout << "check" << endl;
			flag = true;
		}
		for(int i = 0; i < dij[start_point].size(); i++) {
			// cost[도착지점] > cost[출발지점] + weight 
			if(cost[dij[start_point][i].first] >= cost[start_point] + dij[start_point][i].second) {
				cost[dij[start_point][i].first] = cost[start_point] + dij[start_point][i].second;
				q.push(make_pair(-cost[dij[start_point][i].first], dij[start_point][i].first));
			}
		}
		cout << q.top().first << " " << q.top().second << endl;
		if(flag) {
			break;
		}
	}
	
	cout << cost[end] << endl;
	
	return 0;	
}
