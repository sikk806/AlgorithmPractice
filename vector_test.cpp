#include <bits/stdc++.h>

using namespace std;

int check[100];

int main(void) {
	//int check[100];
	fill_n(check, 100, 0);
	vector<vector<int> > check(100);
	
	//check[0] = 123;
	check[0].push_back(456);
	
	cout << &check << endl;
	cout << &check[0] << endl;
	cout << &check[1][0] << endl;
	
}
