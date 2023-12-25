#include <bits/stdc++.h>

using namespace std;

int N;
int lc[27] = {0, };
int rc[27] = {0, };

void preorder(int tmp)
{
	cout << char(tmp+'A'-1);
	if(lc[tmp] != 0) preorder(lc[tmp]);
	if(rc[tmp] != 0) preorder(rc[tmp]);
}

void inorder(int tmp)
{
	if(lc[tmp] != 0) inorder(lc[tmp]);
	cout << char(tmp+'A'-1);
	if(rc[tmp] != 0) inorder(rc[tmp]);
}

void postorder(int tmp)
{
	if(lc[tmp] != 0) postorder(lc[tmp]);
	if(rc[tmp] != 0) postorder(rc[tmp]);
	cout << char(tmp+'A'-1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		char M, L, R;
		cin >> M >> L >> R;
		
		if(L != '.') lc[M-'A'+1] = L - 'A' + 1;
		if(R != '.') rc[M-'A'+1] = R - 'A' + 1;
	}
	
	
	
	preorder(1);
	cout << '\n';
	inorder(1);
	cout << '\n';
	postorder(1);
}

