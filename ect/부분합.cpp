#include <iostream>

using namespace std;

int main(void) {
	int check[100001] = {0,};
	int N, S;
	cin >> N >> S;
	
	for(int i = 0; i < N; i++) {
		cin >> check[i];
	}
	
	int shortest = N+1;
	int point_front = 0, point_back = 0;
	int sum = 0;
	
	while(point_front < N) {
		if(sum < S) {
			sum += check[point_front];
			point_front++;
		}
		else {
			if(shortest > point_front - point_back) {
				shortest = point_front - point_back;
			}
			sum -= check[point_back];
			point_back++;
		}
	}
	
	while(sum >= S && point_back < N) {
		if(shortest > point_front - point_back) {
			shortest = point_front - point_back;
		}
		sum -= check[point_back];
		point_back++;
	}
	
	if(shortest == N+1) {
		cout << "0" << endl;
	}
	else {
		cout << shortest << endl;
	}
	
	return 0;
}
