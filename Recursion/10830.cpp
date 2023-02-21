#include <bits/stdc++.h>

using namespace std;

vector<vector<long long> > temp_power(vector<vector<long long> > &tempA, vector<vector<long long> > &tempB, int N) {
	vector<vector<long long> > power_temp(5, vector<long long>(5, 0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int temp = 0;
			for(int k = 0; k < N; k++) {
				temp += tempA[i][k] * tempB[k][j];
			}
			power_temp[i][j]= temp;
		}
	}
	
	return power_temp;
}

vector<vector<long long> > power(vector<vector<long long> > &A, int N, long long B){
	if(B == 1) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				A[i][j] %= 1000;
			}
		}
		return A;
	}
	vector<vector<long long> > temp(5, vector<long long>(5, 0));
	temp = power(A, N, B/2);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			temp[i][j] %= 1000;
		}
	}
	if(B % 2 == 0) {
		temp = temp_power(temp, temp, N);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				temp[i][j] %= 1000;
			}
		}
		
		return temp;
	}
	else {
		temp = temp_power(temp, temp, N);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				temp[i][j] %= 1000;
			}
		}
		temp = temp_power(temp, A, N);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				temp[i][j] %= 1000;
			}
		}
		return temp;
	}
	
}
int main(void) {
	int N;
	long long B;
	vector<vector<long long> > A(5, vector<long long>(5, 0));
	cin >> N >> B;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	vector<vector<long long> > temp(5, vector<long long>(5, 0));
	temp = power(A, N, B);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	
}
