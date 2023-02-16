#include <bits/stdc++.h>

using namespace std;

vector picnic(vector<pair<int, int> > group, int n, int m) {
	
}

int main(void) {
	vector<pair<int, int> > group;
	int C, n, m, Coup1, Coup2;
	cin >> C;
	
	for(int i = 0; i < C; i++) {
		cin >> n >> m;
		for(int j = 0; j < m; j++) {
			cin >> Coup1 >> Coup2;
			group.push_back(make_pair<Coup1, Coup2>);
		}
	}
}
