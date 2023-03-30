#include <bits/stdc++.h>

using namespace std;

int fri[2000];
int check[2000];
int answer;

vector<vector<int> > con;

void backtracking(int people, int cnt) {
	if(cnt == 5) {
		answer = 1;
		return;
	}
	check[people] = 1;
	for(int i = 0; i < con[people].size(); i++) {
		if(check[con[people][i]] == 0) {
			backtracking(con[people][i], cnt+1);
		}
	}
	check[people] = 0;
}

int main(void) {
	fill_n(fri, 2000, 0);
	vector<vector<int> > fri(2000);
	con = fri;
	fri.erase(fri.begin(), fri.end());
	
	int N, M;
	cin >> N >> M;
	
	int a, b;
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	
	answer = 0;
	
	for(int i = 0; i < N; i++) {
		int cnt = 1;
		backtracking(i, cnt);
		if(answer == 1) {
			cout << "1";
			break;
		}
	}
	if(answer == 0) {
		cout << "0";
	}
}
