#include <bits/stdc++.h>

using namespace std;

int V;
vector< vector<pair<int, int>> > tree(100001);

int main(void)
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int answer = 0;
	cin >> V;
	for(int i = 1; i <= V; i++)
	{
		int vertex;
		cin >> vertex;
		
		while(1)
		{
			int arrive_vertex, len;
			cin >> arrive_vertex;
			if(arrive_vertex == -1) break;
			cin >> len;
			tree[vertex].push_back(make_pair(arrive_vertex, len));
		}
	}
	
	queue<int> q;
	q.push(1);
	int tmp = 1;
	while(1)
	{
		int check[100001] = {0, };
		int len[100001] = {0, };
		check[tmp] = 1;
		while(!q.empty())
		{
			tmp = q.front();
			q.pop();
			for(int i = 0; i < tree[tmp].size(); i++)
			{
				if(check[tree[tmp][i].first] == 0)
				{
					q.push(tree[tmp][i].first);
					check[tree[tmp][i].first] = 1;
					len[tree[tmp][i].first] = len[tmp] + tree[tmp][i].second;
				}
			}
		}
		int mx = *max_element(len + 1, len + V + 1);
		if(answer < mx) 
		{
			answer = mx;
			q.push(tmp);
		}
		else break;
	}
	
	cout << answer;
}
