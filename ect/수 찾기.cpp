#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int num[100001] = {0, };
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> num[i];
	}
	
	sort(num, num+N);
	
	int M, find_num;
	cin >> M;
	for(int i = 0; i < M; i++) {
		cin >> find_num;
		int start = 0;
		int end = N-1;
		int middle = (start+end) / 2;
		while(start < end) {
			if(num[middle] == find_num) {
				cout << "1\n"; 
				break;
			}
			else if(num[middle] > find_num) {
				end = middle-1;
			}
			else {
				start = middle+1;
			}
			middle = (start+end) / 2;
		}
		if(start >= end) {
			if(num[middle] == find_num) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}
	
	return 0;
}
