#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int k = *max_element(arr, arr+10);
	
	cout << k << endl;
}
