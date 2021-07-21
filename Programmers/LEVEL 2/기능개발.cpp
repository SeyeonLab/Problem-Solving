#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> st;
    int release = 0;
    
    for (int i = 0; i < progresses.size(); i++) {
        int count = 0;
        
        while (progresses[i] < 100) {
            count++;
            progresses[i] += speeds[i];
        }
        
        if (st.empty()) {
            st.push(count);
            release++;
        }
        else {
            if (st.top() >= count) {
                release++;
            }
            else {
                st.pop();
                st.push(count);
                answer.push_back(release);
                release = 1;
            }
        }
    }
    answer.push_back(release);
    return answer;
}