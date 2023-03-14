#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int answer_size = number.length() - k;
    int start = 0;
    int big = 0;
    for(int i = 0; i < answer_size; i++) {
        for(int j = start; j <= k; j++) {
            if(number[j] - '0' > big) {
                big = number[j] - '0';
                start = j + 1;
            }
        }
        k++;
        answer += (big + '0');
        big = 0;
    }
    
    return answer;
}
