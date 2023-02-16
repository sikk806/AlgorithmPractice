#include <bits/stdc++.h>

using namespace std;

double calculate(vector<int> price, int N, int L){
	double min = 999;
	double sum;
	cout << N << " " << L << endl;
	for(int i = L; i <= N; i++) {
		for(int j = 0; j < N-i+1; j++) {
			sum = 0;
			for(int k = j; k < i+j; k++) {
				sum += price[k];
			}
			sum /= i;
			if(min > sum) {
				min = sum;
			}
		}
	}
	return min;
}

int main(void) {
	cout.setf(ios::fixed);
  	cout.precision(11);
	
	int C, N, L;
	vector<int> price;
	
	cin >> C;
	for(int i = 0; i < C; i++) {
		cin >> N >> L;
		for(int j = 0; j < N; j++) {
			int pr;
			cin >> pr;
			price.push_back(pr);
		}
		
		cout << calculate(price, N, L) << endl;
	}
	return 0;
}
