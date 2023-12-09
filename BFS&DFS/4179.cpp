#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char maze[1001][1001] = {0, };
int fire[1001][1001] = {0, };

int main(void)
{
	int R, C;
	cin >> R >> C;
	
	queue<pair<int, int> > q_JH;
	queue<pair<int, int> > q_fire;
	
	for(int i = 1; i <= R; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			cin >> maze[i][j];
			if(maze[i][j] == 'J')
			{
				q_JH.push(make_pair(i, j));
			}
			if(maze[i][j] == 'F')
			{
				q_fire.push(make_pair(i, j));
				fire[i][j] = 1;
			}
		}
	}
	
	int cnt_JH = q_JH.size();
	int cnt_fire = q_fire.size();
	int answer = 1;
	bool bOut = false;
	
	while(!q_fire.empty())
	{
		if(cnt_fire == 0)
		{
			cnt_fire = q_fire.size();
		}
		cnt_fire--;
		int x = q_fire.front().first;
		int y = q_fire.front().second;
		q_fire.pop();
		
		for(int i = 0; i < 4; i++)
		{
			if(x + dx[i] > 0 && x + dx[i] <= R 
				&& y + dy[i] > 0 && y + dy[i] <= C
				&& maze[x + dx[i]][y + dy[i]] == '.'
				&& !fire[x + dx[i]][y + dy[i]]
				|| maze[x + dx[i]][y + dy[i]] == 'J')
			{
					q_fire.push(make_pair(x + dx[i], y + dy[i]));
					fire[x + dx[i]][y + dy[i]] = fire[x][y] + 1;
			}
		}
	}
	

	while(!q_JH.empty())
	{
		if(cnt_JH == 0)
		{
			answer++;
			cnt_JH = q_JH.size();
		}
		
		cnt_JH--;
		int x = q_JH.front().first;
		int y = q_JH.front().second;
		q_JH.pop();
		
		for(int i = 0; i < 4; i++)
		{
			if(x + dx[i] > 0 && x + dx[i] <= R 
				&& y + dy[i] > 0 && y + dy[i] <= C
				&& maze[x + dx[i]][y + dy[i]] == '.'
				&& (fire[x + dx[i]][y + dy[i]] > answer + 1
				|| fire[x + dx[i]][y + dy[i]] == 0))
			{
				q_JH.push(make_pair(x + dx[i], y + dy[i]));
				maze[x + dx[i]][y + dy[i]] = 'J';
			}
			else if(x + dx[i] <= 0 || x + dx[i] > R 
				|| y + dy[i] <= 0 || y + dy[i] > C)
			{
				bOut = true;
				break;
			}
		}
		if(bOut) break;
	}
	
	if(bOut) cout << answer;
	else cout << "IMPOSSIBLE";
	
}
