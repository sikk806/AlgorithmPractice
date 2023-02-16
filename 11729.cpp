#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> hanoi(stack<int> one, stack<int> two, stack<int> three, int N, condition) {
	if(three.size() == N) {
		return condition;
	}
	
	// 비어있는 상황
	if(!one.empty()) {
		if(two.empty()) {
			two.push(one.top());
			one.pop();
			answer = hanoi(one, two, three, N, condition);
		}
		if(three.empty()) {
			three.push(one.top());
			one.pop();
			answer = hanoi(one, two, three, N, condition);
		}
	}
	if(!two.empty()) {
		
	}
};

int main(void) {
	int N;
	cin >> N;
	stack<int> one, two, three;
	
	for(int i = N; i > 0; i--) {
		one.push(N);
	}
	
	vector<pair<int, int>> answer;
	vector<pair<int, int>> condition;
	answer = hanoi(one, two, three, N, condition);
	
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << endl;
	}
}
