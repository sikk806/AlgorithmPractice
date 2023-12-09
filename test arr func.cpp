#include <iostream>

using namespace std;

void func(arr[])
{
	arr[1] = 100;
	arr[4] = 100;
}

int main(void)
{
	int arr[10] = {0, };
	
	func(arr);
	
	for(int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}
