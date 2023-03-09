#include <bits/stdc++.h>

using namespace std;

struct OWtest {
	virtual void TP() const final { cout << "Hello-P" << endl;	}
	virtual void TP2() { cout << "Hello-P2" << endl; }
};
struct OWtest_ch : public OWtest {
	void TP() override { cout << "Hello-C" << endl; }
	void TP2() { cout << "Hello-C2" << endl; }
};

enum COLOR {
	RED,
	BLUE,
	GREEN
};

const int a = 5;

void test() {
	int a = 3;
	cout << ++a << endl;
}

int main(void) {
//	const int a = 5;
//	cout << a << endl;

	test();
//	const int a = 3;

	cout << a << endl;
	
	OWtest parent;
	parent.TP();
	parent.TP2();
	
	OWtest_ch child;
	child.TP();
	child.TP2();
	
	
	COLOR c(RED);
	COLOR c1(BLUE);
	if(c != c1) {
		cout << "HELLO";
	}
	
	
//	cout << c << endl;
	
}
