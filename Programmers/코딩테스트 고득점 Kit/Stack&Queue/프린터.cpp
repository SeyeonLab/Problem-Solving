#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<int> q;    
    int answer = 0;
    
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push(i);
    }
    
    while (!pq.empty()) {
        int index = q.front();
        int p = priorities[q.front()];
        q.pop();
        
        if (p == pq.top()) {
            pq.pop();
            answer++;
            
            if (location == index)
                break;
        }  
        else
            q.push(index);
    }
    
    return answer;
}