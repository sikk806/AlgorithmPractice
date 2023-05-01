#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; i++) {
		string function = "";
		int size = 0;
		vector<int> arr;
		
		cin >> function;
		cin >> size;
		
		string cut = "";
		cin >> cut;
		cut = cut.substr(1, cut.size()-2);
		
		istringstream ss(cut);
		string stringBuffer;
		while(getline(ss, stringBuffer, ',')) {
			arr.push_back(stoi(stringBuffer));
		}
		
		sort(arr.begin(), arr.end());
		
		int erase_front_point = 0;
		int arr_size = arr.size();
		int erase_back_point = arr_size - 1;
		int erase_point = 0;
		int error_flag = 0;
		int reverse_flag = 0; // 0 : 정순, 1 : 역순 
	
		for(int j = 0; j < function.size(); j++) {
			if(function[j] == 'D') {
				if(arr_size == 0) {
					error_flag = 1;
					break;
				}
				if(reverse_flag == 0) {
					erase_front_point++;
					erase_point++;
				}
				else {
					erase_back_point--;
					erase_point--;
				}
				arr_size--;
			}
			else if(function[j] == 'R') {
				if(reverse_flag == 0) {
					erase_point = erase_back_point;
					reverse_flag = 1;
				}
				else {
					erase_point = erase_front_point;
					reverse_flag = 0;
				}
			}
		}
	
		if(error_flag == 0) {
			cout << "[";
			if(arr_size == 0) {
				cout << "]\n";
			}
			else if(reverse_flag == 0) {
				for(int j = erase_front_point; j <= erase_back_point; j++) {
					if(j == erase_back_point) 
						cout << arr[j] << "]\n";
					else
						cout << arr[j] << ",";
				}
			}
			else if(reverse_flag == 1){
				for(int j = erase_back_point; j >= erase_front_point; j--) {
					if(j == erase_front_point) 
						cout << arr[j] << "]\n";
					else
						cout << arr[j] << ",";
				}
			}
		}
		else {
			cout << "error\n";
		}
	}
	
	return 0;
}
