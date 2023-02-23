#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int map[101][101] = {0, };
    for(int i = 0; i < puddles.size(); i++) {
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1 && j == 1) {
                map[i][j] = 1;
            }
            else if(map[i][j] == -1) {
                map[i][j] = 0;
            }
            else {
                map[i][j] = (map[i-1][j] + map[i][j - 1]) % 1000000007;
            }
        }
    }
    
    answer = map[n][m];
    
    return answer;
}
