#include <bits/stdc++.h>

using namespace std;

int city[300001];
int check[300001];

int main(void) {
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	fill_n(check, 300001, 0);
	fill_n(city, 300001, 0);
	vector<vector<int>> city(300001);
	
	int A, B;
	for(int i = 0; i < M; i++) {
		cin >> A >> B;
		city[A].push_back(B);
		city[B].push_back(A);
	}
	
	queue<int> q;
	q.push(X);
	check[X] = 1;
	
	int cnt = 0;
	int q_size = q.size();
	
	while(!q.empty() && cnt != K) {
		if(q_size == 0) {
			q_size = q.size();
			cnt++;
		}
		
		int start_point = q.front();
		q.pop();
		q_size--;
		
		for(int i = 0; i < city[start_point].size(); i++) {
			if(check[city[start_point][i]] == 0) {
				check[city[start_point][i]] = 1;
				q.push(city[start_point][i]);
			}
		}
	}
	
	if(q.empty()) {
		cout << "-1";
	}
	else {
		for(int i = 0; i < q.size(); i++) {
			cout << q.front() << endl;
			q.pop();
		}
	}
	
}
