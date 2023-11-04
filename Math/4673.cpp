#include <bits/stdc++.h>

using namespace std;

int nums[10001] = {0, };

int main(void)
{
	
	for(int i = 1; i <= 10000; i++)
	{
		if(nums[i] == 0)
		{
			int n = i;
			cout << n << endl;
			while(n < 10001)
			{
				string str = to_string(n);
				for(int j = 0; j < str.length(); j++)
				{
					char a = str[j];
					n += a - '0';
				}
				nums[n] = 1;
			}
		}
	}
}
