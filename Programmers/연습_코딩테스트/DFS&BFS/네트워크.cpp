#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool visited[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int dfs = 0; dfs < computers.size(); dfs++) {
        stack<int> s;
        s.push(dfs);
        if (visited[dfs] == true)
            continue;
        
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            visited[x] = true;
            
            for (int i = 0; i < computers.size(); i++) {
                if (computers[x][i] != 0 && !visited[i]) {
                    s.push(i);
                }
            }
        }
        
        answer++;
    }
    
    return answer;
}