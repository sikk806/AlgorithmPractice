#include <bits/stdc++.h>

using namespace std;

int answer;

void calculate(vector<string> arr, int cal_num) 
{
    if(cal_num == 0) {
        if(answer < stoi(arr[0]))
            answer = stoi(arr[0]);
        return;
    }
    vector<string> reset_arr;
    reset_arr = arr;
    for(int i = 0; i < cal_num; i++) {
        arr = reset_arr;
        int front = stoi(arr[i*2]); //ASCII
        int back = stoi(arr[i*2 + 2]);
        if(arr[i*2+1] == "+") {
            arr[i*2] = to_string(front + back);
        }
        else {
            arr[i*2] = to_string(front - back);
        }
        arr.erase(arr.begin() + (i*2+2));
        arr.erase(arr.begin() + (i*2+1));
        calculate(arr, (cal_num-1));
    }
}

int solution(vector<string> arr)
{
    answer = -9999999;
    int cal_num = arr.size() / 2;
    
    calculate(arr, cal_num);
    
    return answer;
}
