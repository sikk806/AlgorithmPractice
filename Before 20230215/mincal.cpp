#include <iostream>

using namespace std;

int main(void) {
	int second;
	int min;
	int num;
	int sum_h = 0;
	int sum_m = 0;
	int sum_s = 0;
	
	cin >> num;
	
	for(int i = 0; i < num; i++) {
		cin >> min >> second;
		sum_s += second;
		sum_m += min;
		
		if(sum_s >= 60) {
			sum_s -= 60;
			sum_m += 1;
		}
		if(sum_m >= 60) {
			sum_m -= 60;
			sum_h += 1;
		}
	}
	
	cout << sum_h << " " << sum_m << " " << sum_s << endl;
}
