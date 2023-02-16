#include<bits/stdc++.h>

using namespace std;

int pos_x[4] = {0, 1, 0, -1};
int pos_y[4] = {1, 0, -1, 0};
int check[101][101] = {0,};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = 0;
    int q_x, q_y;
    queue<pair<int, int> > q;
    
    q.push(make_pair(0, 0));
    check[0][0] = 1;
    
    int q_size = q.size();
    answer++;
    
    while(!q.empty()) {
        if(q_size <= 0) {
            q_size = q.size();
            answer++;
        }
        q_x = q.front().first;
        q_y = q.front().second;
        if(q_x == n-1 && q_y == m-1) {
            break;
        }
        q.pop();
        for(int i = 0; i < 4; i++) {
            int dx = q_x+pos_x[i];
            int dy = q_y+pos_y[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m) {
                if(check[dx][dy] == 0 && maps[dx][dy] == 1) {
                   q.push(make_pair(dx, dy));
                   check[dx][dy] = 1;
                }
            }
        }
        q_size--;
    }
    if(q_x != n-1 || q_y != m-1) {
        answer = -1;
    }
    
    return answer;
}
