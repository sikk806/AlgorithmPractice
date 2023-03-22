#include <bits/stdc++.h>

using namespace std;

class Test{
	int k;
public:
	void notconst(int d) {
		k = 3;
	}

	const int& cal(int d) {
		k = 4;
		int& A = d;
		//cout << &A << endl;
		return A;
	}
};

int main(void) {
	int a = 5;
	int b = 4;
	
	Test t;
	
	char d = '3';
	//cout << &d << endl;
	const int& c = t.cal(d);
	
	//int *p = &d;

	char hello[] = "Hello";
	char gello[] = "Gello";
	
	const char * p= hello;
	//const char *p = &d;
	//int *const p = &b;
	
	//*p = &d;
	
	//*p = 1;
	
	//cout << p << endl;
	int k;
	cout << k << endl;
	//cout << b << endl;
	//hello[0] = 'G';
	//cout << p << endl;
	//int& C = t.cal(d);
}
