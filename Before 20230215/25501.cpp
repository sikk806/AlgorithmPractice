#include <bits/stdc++.h>

using namespace std;

int cnt;

int recursion(string s, int l, int r){
	cnt += 1;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string s){
    return recursion(s, 0, s.length()-1);
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N;
	string str;
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cnt = 0;
		cin >> str;
		cout << isPalindrome(str) << " ";
		cout << cnt << "\n";
	}
}
