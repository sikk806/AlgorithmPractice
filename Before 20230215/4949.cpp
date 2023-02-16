#include <bits/stdc++.h>

using namespace std;

int main(void) {
	stack<char> cover;
	
	while(1) {
		bool check = false;
		while(!cover.empty()) {
			cover.pop();
		}
		string str;
		getline(cin, str);
		if(str == ".") {
			break;
		}
		
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == '(' || str[i] == '[') {
				cover.push(str[i]);
			}
			else if(str[i] == ')') {
				if(!cover.empty() && cover.top() == '(') {
					cover.pop();
				}
				else if(cover.empty() || cover.top() != '(') {
					check = true;
					break;
				}
			}
			else if(str[i] == ']') {
				if(!cover.empty() && cover.top() == '[') {
					cover.pop();
				}
				else if(cover.empty() || cover.top() != '[') {
					check = true;
					break;
				}
			}
			
		}
		if(cover.empty() && !check) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		
	}
	
	return 0;
	
}
