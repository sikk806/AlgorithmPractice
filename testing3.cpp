#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int a = 0;
	int *ptr;
	int **ptr2;
	
	ptr2 = &ptr;
	
	ptr = &a;
	
	cout << ptr2 << endl;
	cout << *ptr2 << endl;
	cout << ptr << endl;
	
}
