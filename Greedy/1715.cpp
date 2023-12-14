#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int answer = 0;
	int N;
	cin >> N;
	
	priority_queue<int> q;
	
	for(int i = 0; i < N; i++)
	{
		cin >> answer;
		q.push(-answer);
	}
	
	answer = 0;
	
	while(q.size() > 1)
	{
		int first = -q.top();
		q.pop();
		int second = -q.top();
		q.pop();
		
		q.push(- first - second);
		answer += (first + second);
	}
	
	cout << answer;
}
