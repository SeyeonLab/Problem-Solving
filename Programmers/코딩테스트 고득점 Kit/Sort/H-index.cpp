#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    int count = 0;
    int size = citations.size();
    int h;
    sort(citations.begin(), citations.end(), compare);
    h = citations[0];
    while (h >= 0) {
        count = 0;
        for (int i = 0; i < size; i++) {
            if (citations[i] < h)
                break;
            count++;
        } 
        
        if (count >= h)
            break;
        
        h--;  
    }
    answer = h;    
    return answer;
}