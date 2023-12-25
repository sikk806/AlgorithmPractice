#include <bits/stdc++.h>

using namespace std;

int N, cut, root, answer;
vector<vector<int> > tree(51);

void find(int tmp)
{
	if(tree[tmp].size() == 0) answer++;
	for(int i = 0; i < tree[tmp].size(); i++)
	{
		if(tree[tmp][i] != cut) find(tree[tmp][i]);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	answer = 0;
	cin >> N;
	
	
	for(int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if(a == -1) root = i;
		else
		{
			tree[a].push_back(i);
		}
	}
	cin >> cut;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < tree[i].size(); i++)
		{
			if(tree[i][j] == cut)
			{
				tree[i].erase(tree[i].begin() + j);
				break;
			}
		}
	}
	
	if(cut == root)
	{
		cout << "0";
		return 0;
	}
	
	tree[cut].clear();
	
	find(root);
	cout << answer;
}
