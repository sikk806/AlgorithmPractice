#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int num;
	int j = 0;
	int arr[100001] = {0, };
	
	cin >> num;
	
	vector<char> answer;
	stack<int> s;
	
	for(int i = 0; i < num; i++) {
		int cal;
		cin >> arr[i];
	}
	
	// i : 숫자 순서 (1~num)
	// j : 목표 수열 순서 
	// stack : 숫자 순서대로 push 
	for(int i = 1; i <= num;) {
		if(s.empty()) {
			s.push(i);
			answer.push_back('+');
			i++; 
		}
		if(arr[j] == s.top()) {
			s.pop();
			answer.push_back('-');
			j++;
		}
		else {
			s.push(i);
			answer.push_back('+');
			i++;
		}
	}
	
	while(!s.empty()) {
		if(arr[j] != s.top()) {
			break;
		}
		answer.push_back('-');
		s.pop();
		j++;
	}
	
	
	
	if(!s.empty()) {
		cout << "NO" << '\n';
	}
	else {
		for(int i = 0; i < answer.size(); i++) {
			cout << answer[i] << '\n';
		}
	}
	
	return 0;
}
