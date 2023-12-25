#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int a[10];
	for(auto &i : a)
	{
		cin >> i;
	}
	
	sort(a, a+10);
	
	cout << binary_search(a, a+10, 3) << endl;
	cout << lower_bound(a, a+10, 3) << endl;
	cout << upper_bound(a, a+10, 3) << endl;
	cout << endl;
	
	vector<int> v;
	for(int i = 0; i < 10; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());
	cout << v[0] << endl;
	
	cout << binary_search(v.begin(), v.end(), 3) << endl;
	cout << *lower_bound(v.begin(), v.end(), 3) << endl;
	cout << *upper_bound(v.begin(), v.end(), 3) << endl;
	
	auto range = equal_range(v.begin(), v.end(), 3);
	cout << &range << endl;
	cout << *range.first << endl;
	cout << *range.second << endl;
	
	set<int> s;
	for(int i = 0; i < 10; i++)
	{
		int temp;
		cin >> temp;
		s.insert(temp);
	}
	
	cout << binary_search(s.begin(), s.end(), 3) << endl;
	cout << *lower_bound(s.begin(), s.end(), 3) << endl;
	cout << *upper_bound(s.begin(), s.end(), 3) << endl;
	
}
