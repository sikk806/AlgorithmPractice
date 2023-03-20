#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<string, int> result;
    result.insert({"R", 0});
    result.insert({"T", 0});
    result.insert({"C", 0});
    result.insert({"F", 0});
    result.insert({"J", 0});
    result.insert({"M", 0});
    result.insert({"A", 0});
    result.insert({"N", 0});
    
    int survey_length = survey.size();
    
    for(int i = 0; i < survey_length; i++) {
        if(survey[i] == "RT") {
            if(choices[i] < 4) {
                result["R"] += (4 - choices[i]);
            }
            else if(choices[i] > 4) {
                result["T"] += (choices[i] - 4);
            }
        }
        else if(survey[i] == "TR") {
            if(choices[i] < 4) {
                result["T"] += (4 - choices[i]);
            }
            else if(choices[i] > 4) {
                result["R"] += (choices[i] - 4);
            }
        }
        else if(survey[i] == "CF") {
            if(choices[i] < 4) {
                result["C"] += (4 - choices[i]);
            }
            else if(choices[i] > 4) {
                result["F"] += (choices[i] - 4);
            }
        }
        else if(survey[i] == "FC") {
            if(choices[i] < 4) {
                result["F"] += (4 - choices[i]);
            }
            else if(choices[i] > 4) {
                result["C"] += (choices[i] - 4);
            }
        }
        else if(survey[i] == "JM") {
            if(choices[i] < 4) {
                result["J"] += (4 - choices[i]);
            }
            else if(choices[i] > 4) {
                result["M"] += (choices[i] - 4);
            }
        }
        else if(survey[i] == "MJ") {
            if(choices[i] < 4) {
                result["M"] += (4 - choices[i]);
            }
            else if(choices[i] > 4) {
                result["J"] += (choices[i] - 4);
            }
        }
        else if(survey[i] == "AN") {
            if(choices[i] < 4) {
                result["A"] += (4 - choices[i]);
            }
            else if(choices[i] > 4) {
                result["N"] += (choices[i] - 4);
            }
        }
        else {
            if(choices[i] < 4) {
                result["N"] += (4 - choices[i]);
            }
            else if(choices[i] > 4) {
                result["A"] += (choices[i] - 4);
            }
        }
    }
    
    if(result["R"] >= result["T"])
        answer += "R";
    else
        answer += "T";
    
    if(result["C"] >= result["F"])
        answer += "C";
    else
        answer += "F";
    
    if(result["J"] >= result["M"])
        answer += "J";
    else
        answer += "M";
    
    if(result["A"] >= result["N"])
        answer += "A";
    else
        answer += "N";
    
    return answer;
}
