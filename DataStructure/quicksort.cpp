#include <bits/stdc++.h>

using namespace std;

void quick_sort(vector<int> &arr, int left, int right) {
	int i = left;
	int j = right;
	int pivot = arr[(left+right) / 2];
	
	while(i <= j) {
		while(arr[i] < pivot) i++;
		while(arr[j] > pivot) j--;
		if(i <= j ) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	
	if(left < j) quick_sort(arr, left, j);
	if(right > i) quick_sort(arr, i, right);
	
}

int main(void) {
	vector<int> arr = {3, 7, 1, 5, 2, 9, 4, 6, 8};
	int n = arr.size();
	
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	quick_sort(arr, 0, n-1);
	
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}

