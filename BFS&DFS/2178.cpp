#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void)
{
	int answer = 1;
	int N, M;
	cin >> N >> M;
	
	char maze[101][101] = {0, };
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin >> maze[i][j];
		}
	}
	
	queue<pair<int, int> > q;
	q.push(make_pair(1, 1));
	maze[1][1] = '0';
	int cnt = q.size();
	
	while(!q.empty())
	{
		if(cnt == 0)
		{
			cnt = q.size();
			answer++;
		}
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt--;
		if(x == N && y == M) break;
		
		for(int i = 0; i < 4; i++)
		{
			if(x + dx[i] > 0 && x + dx[i] <= N && y + dy[i] > 0 && y + dy[i] <= M
			&& maze[x + dx[i]][y + dy[i]] == '1')
			{
				maze[x + dx[i]][y + dy[i]] = '0';
				q.push(make_pair(x + dx[i], y + dy[i]));
			}
		}
	}
	
	cout << answer;
	
}
