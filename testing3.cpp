#include <bits/stdc++.h>

using namespace std;

struct MyStruct
{
  int i;
};

MyStruct bar () 
{
  MyStruct result = { 5 };
  return result;
}

/* won't compile; 'lvalue required as unary & operand */
void qux () 
{
  int *j = &bar().i;
}

int main(void) {
	qux();
}
