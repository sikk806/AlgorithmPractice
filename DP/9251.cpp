#include <bits/stdc++.h>

using namespace std;

int LCS[1001][1001] = {0, };

int main(void)
{
	int lcs = 0;
	bool check = false;
	string s1 = "";
	string s2 = "";
	
	cin >> s1;
	cin >> s2;
	
	for(int i = 0; i < s1.size(); i++)
	{
		for(int j = 0; j < s2.size(); j++)
		{
			if(s1[i] == s2[j])
			{
				for(int k = 0; k <= j; k++)
				
			}
		}
	}
	
	cout << lcs;
}
