#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    int cnt = 0;
    int q1 = 0;
    int q2 = 0;
    int queue_size = queue1.size();
    long avg_sum = 0;
    long sum1 = 0;
    long sum2 = 0;
    
    for(int i = 0; i < queue_size; i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    if((sum1 + sum2) % 2 != 0) {
        return -1;
    }
    queue_size <<= 2;
    while(sum1 != sum2 && queue_size-1 != cnt && q1 != queue_size && q2 != queue_size) {
        if(sum1 > sum2) {
            queue2.push_back(queue1[q1]);
            sum1 -= queue1[q1];
            sum2 += queue1[q1];
            q1++;
        }
        else if(sum1 < sum2) {
            queue1.push_back(queue2[q2]);
            sum2 -= queue2[q2];
            sum1 += queue2[q2];
            q2++;
        }
        cnt++;
    }
    if(sum1 != sum2) {
        answer = -1;
    }
    else {
        answer = cnt;
    }
    
    return answer;
}
