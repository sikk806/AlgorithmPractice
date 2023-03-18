#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    //int check[200000001] = {0, };
    int between;
    
    for(int i = 0; i < stations.size()-1; i++) {
        if(stations[i] + w < stations[i+1] - w) {
            between = (stations[i+1] - w) - (stations[i] + w) - 1;
            if(between % (2*w + 1) != 0) {
                answer += between / (2*w + 1) + 1;
            }
            else {
                answer += between / (2*w + 1);
            }
        }
    }
    
    int check = 0;
    
    if(stations[0] - w > 1) {
        between = (stations[0] - w) - 1;
        if(between % (2*w + 1) != 0) {
            answer += between / (2*w + 1) + 1;
        }
        else {
            answer += between / (2*w + 1);
        }
    }
    
    if(stations[stations.size()-1] + w < n) {
        between = n - (stations[stations.size()-1] + w);
        if(between % (2*w + 1) != 0) {
            answer += between / (2*w + 1) + 1;
        }
        else {
            answer += between / (2*w + 1);
        }
    }
    
    return answer;
}
