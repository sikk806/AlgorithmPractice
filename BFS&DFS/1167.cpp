#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>> >tree(100001);

const int INF = 1000000001;
int shortest[100001];
int check[100001];
int answer = 0;

void dfs(int start_vertex) {
	check[start_vertex] = 1;
	int ver_size = tree[start_vertex].size();
	for(int i = 0; i < ver_size; i++) {
		int next_ver = tree[start_vertex][i].first;
		int ver_edge = tree[start_vertex][i].second;
		if(check[next_ver] == 0) {
			if(shortest[next_ver] > shortest[start_vertex] + ver_edge) {
				shortest[next_ver] = shortest[start_vertex] + ver_edge;
			}
			dfs(next_ver);
		}
		check[start_vertex] = 0;
	}
}



int main(void) {
	answer = 0;
	int V, vertex, edge, main_v;
	
	cin >> V;
	
	for(int i = 1; i <= V; i++) {
		cin >> main_v;
		while(1) {
			cin >> vertex;
			if(vertex == -1) {
				break;
			}
			cin >> edge;
			tree[main_v].push_back(make_pair(vertex, edge));
		}
	}
	
	for(int i = 1; i <= V; i++) {
		int check[100001] = {0, };
		fill_n(check, 100001, 0);
		fill_n(shortest, 100001, INF);
		shortest[i] = 0;
		dfs(i);
		
		for(int i = 1; i <= V; i++) {
			if(answer < shortest[i]) {
				answer = shortest[i];
			}
		}
	}
	
	cout << answer << endl;
}
