#include <bits/stdc++.h>

using namespace std;

int cost[100001];
int dij[100001];

int main(void) {
	fill_n(cost, 100001, 100002);
	fill_n(dij, 100001, 2);
	
	vector<vector<pair<int, int>> > dij(100001);
	
	int N, K;
	cin >> N >> K;
	
	dij[0].push_back(make_pair(1, 1)); // 0 -> 1
	
	dij[1].push_back(make_pair(0, 1)); // 1 -> 0
	dij[1].push_back(make_pair(2, 0)); // 1 -> 2 (순간이동이 더 빠름) 
	
	for(int i = 2; i < 100001; i++) {
		dij[i].push_back(make_pair(i-1, 1));
		if(i+1 < 100001) {
			dij[i].push_back(make_pair(i+1, 1));
			if(i*2 < 100001) {
				dij[i].push_back(make_pair(i*2, 0));
			}
		}
	}
	
	cost[N] = 0;
	// weight, vertex
	priority_queue<pair<int, int>> q;
	q.push(make_pair(-cost[N], N));
	
	while(!q.empty()) {
		int start_point_cost = q.top().first;
		int start_point = q.top().second;
		q.pop();
		
		if(start_point == K) {
			cout << cost[K] << endl;
			break;
		}
		for(int i = 0; i < dij[start_point].size(); i++) {
			// 도착지 cost > 출발지 cost + weight  
			if(cost[dij[start_point][i].first] > cost[start_point] + dij[start_point][i].second) {
				cost[dij[start_point][i].first] = cost[start_point] + dij[start_point][i].second;
				q.push(make_pair(-cost[dij[start_point][i].first], dij[start_point][i].first));
			}
		}
	}
	
	return 0;
}
