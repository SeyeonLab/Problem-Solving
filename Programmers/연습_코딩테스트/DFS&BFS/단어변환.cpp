#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;
const int MAX = 51;

bool check;
bool visited[MAX];
map<string, int> m;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int size = begin.size();
    
    queue<string> q;
    q.push(begin);
    m[begin] = 0;
    
    while (!q.empty()) {
        string x = q.front();
        q.pop();
        
        if (!target.compare(x)) {
            check = true;
            break;
        }
        
        for (int i = 0 ; i < words.size(); i++) {
            int count = 0;
            if (visited[i]) continue;
            
            for (int j = 0; j < size; j++) {
                if (x[j] != words[i][j]) count++;
            }
            if (count == 1) {
                q.push(words[i]);
                visited[i] = true;
                m[words[i]] = m[x] + 1;
            }
        }
    }
    
    if (check) answer = m[target];
    else answer = 0;
    
    return answer;
}