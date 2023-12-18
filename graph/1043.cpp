#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	// ���� �ƴ� ��� �� 
	int known_num;
	cin >> known_num;
	
	int check[N+1] = {0, };
	int visited[N+1] = {0, };
	
	// ���� �ƴ� ��� ť (BFS�� Ǯ ����) 
	queue<int> q;
	for(int i = 0; i < known_num; i++)
	{
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	
	// 0 ~ M-1 : ��Ƽ ����Ʈ 
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
	
	// N�� 1������ �����ϱ� ������ +1.
	// ���� �ƴ� ��� �׷��� (set���� vector�� �ߺ� ����) 
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
	
	// BFS�� ���� �˰� �ִ�  ����� üũ 
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
