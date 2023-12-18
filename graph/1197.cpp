#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;

int main(void)
{
	int V, E, A, B, C;
	cin >> V >> E;
	
	// 트리 생성 (V+1 : 1~V이기 때문.)
	vector< vector<pair<int, int> >> spanning_tree(V+1); 
	
	int weight[10001];
	fill(weight, weight + 10001, MAX);
	
	int visited[10001] = {0, };
	
	for(int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		spanning_tree[A].push_back(make_pair(B, C));
		spanning_tree[B].push_back(make_pair(A, C));
	}
	
	int min = MAX;
	weight[1] = 0;
	
	while(1)
	{
		int smallest = MAX;
		int smallest_i = 10001;
		for(int i = 1; i <= V; i++)
		{
			if(!visited[i] && smallest > weight[i])
			{
				smallest = weight[i];
				smallest_i = i;
			}
		}
		if(smallest_i == 10001) break;
		visited[smallest_i] = 1;
		
		for(auto &it : spanning_tree[smallest_i])
		{
			if(!visited[it.first] && weight[it.first] > it.second )
			{
				weight[it.first] = it.second;
			}
		}
	}
	
	int answer = 0;
	
	for(int i = 1; i <= V; i++)
	{
		answer += weight[i];
	}
	
	cout << answer;
}
