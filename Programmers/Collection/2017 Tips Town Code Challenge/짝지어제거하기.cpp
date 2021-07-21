#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = -1;
    string temp;
    
    for (int i = 0; i < s.size(); i++) {
        if (temp.back() == s[i]) {
            temp.pop_back();
            continue;
        }
        temp.push_back(s[i]);
    }
    
    if (!temp.empty()) answer = 0;
    else answer = 1;
    
    return answer;
}