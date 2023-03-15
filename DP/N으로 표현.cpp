#include <bits/stdc++.h>

using namespace std;

int DP[9];

int solution(int N, int number) {
    int answer = -1;
    
    fill_n(DP, 9, 0);
    
    set<int> DP[9];
    set<int>::iterator iter_find;
    set<int>::iterator iter_begin;
    set<int>::iterator iter_end;
    
    if(N == number) {
        return 1;
    }
    for(int i = 1; i < 9; i++) {
        int j = 0;
        int tmp = 0;
        while(j != i) {
            tmp = tmp * 10 + N;
            j++;
        }
        
        DP[i].insert(tmp);
        for(j = 1; j < i; j++) {
            for(iter_begin = DP[j].begin(); iter_begin != DP[j].end(); iter_begin++) {
                for(iter_end = DP[i-j].begin(); iter_end != DP[i-j].end(); iter_end++) {
                    DP[i].insert(*iter_begin+(*iter_end));
                    if(*iter_begin-(*iter_end) >= 0)
                        DP[i].insert(*iter_begin-(*iter_end));
                    if(*iter_end != 0)
                        DP[i].insert(*iter_begin/(*iter_end));
                    DP[i].insert(*iter_begin*(*iter_end));
                }
            }
        }
        if(*DP[i].find(number) == number)
            return i;
    }
    
    
    
    return answer;
}
