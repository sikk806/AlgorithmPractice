#include <bits/stdc++.h>

using namespace std;

int check[20001];
int flag; // 0 : NO , 1 : YES

vector<vector<int> > graph(20001);

// div : 1 or 2 
void dfs(int vertex, int div) {
	if(flag == 0) {
		return;
	}
	int size = graph[vertex].size();
	check[vertex] = div;
	for(int i = 0; i < size; i++) {
		if(check[graph[vertex][i]] == 0) {
			if(div == 1) {
				dfs(graph[vertex][i], 2);
			}
			else {
				dfs(graph[vertex][i], 1);
			}
		}
		else if(check[graph[vertex][i]] == div) {
			flag = 0;
			return;
		}
	}
}

int main(void) {
	int K, V, E;
	
	cin >> K;
	
	for(int i = 0; i < K; i++) {
		fill_n(check, 20001, 0);
		flag = 1;
		cin >> V >> E;
		
		for(int j = 1; j <= V; j++) {
			graph[j].clear();
		}
		
		for(int j = 0; j < E; j++) {
			int first, second;
			cin >> first >> second;
			graph[first].push_back(second);
			graph[second].push_back(first);
		}
		
		for(int j = 1; j <= V; j++) {
			if(check[j] == 0 && flag == 1) {
				dfs(j, 1);
			}
		}
		
		if(flag == 1 || V == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		
	}
}
