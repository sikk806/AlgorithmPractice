#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	// 진실 아는 사람 수 
	int known_num;
	cin >> known_num;
	
	int check[N+1] = {0, };
	int visited[N+1] = {0, };
	
	// 진실 아는 사람 큐 (BFS로 풀 예정) 
	queue<int> q;
	for(int i = 0; i < known_num; i++)
	{
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	
	// 0 ~ M-1 : 파티 리스트 
	vector< vector<int> > parties(M);
	for(int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		for(int j = 0; j < tmp; j++)
		{
			int member;
			cin >> member;
			parties[i].push_back(member);
		}
	}
	
	// N은 1번부터 시작하기 때문에 +1.
	// 서로 아는 사람 그래프 (set으로 vector에 중복 방지) 
	vector< set<int>> known_each(N+1);
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < parties[i].size(); j++)
		{
			for(int k = 0; k < parties[i].size(); k++)
			{
				if(j != k)
				{
					known_each[parties[i][j]].insert(parties[i][k]);
					known_each[parties[i][k]].insert(parties[i][j]);
				}
			}
		}
	}
	
	// BFS로 진실 알고 있는  사람들 체크 
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
		check[top] = 1;
		visited[top] = 1;
		
		set<int>::iterator it;
		for(it = known_each[top].begin(); it != known_each[top].end(); it++)
		{
			if(!visited[*it])
			{
				check[*it] = 1;
				q.push(*it);
			}
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < parties[i].size(); j++)
		{
			if(check[parties[i][j]]) break;
			if(j == parties[i].size()-1) cnt++;
		}
	}
	
	cout << cnt;
	
}
