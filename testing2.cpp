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
		cout << &A << endl;
		return A;
	}
};

int main(void) {
	int a = 5;
	int b = 4;
	
	Test t;
	
	int d = 2;
	cout << &d << endl;
	const int& c = t.cal(d);
	
	int *p = &d;
	
	cout << &p << endl;
	cout << &c << endl;
	//int& C = t.cal(d);
}
