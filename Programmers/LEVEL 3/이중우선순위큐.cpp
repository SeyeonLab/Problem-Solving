#include <string>
#include <vector>
#include <set>

using namespace std;
multiset<int> ms;
multiset<int>::iterator it, it2;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for (int i = 0; i < operations.size(); i++) {
        char c; int n;
        c = operations[i].front();
        n = stoi(operations[i].substr(2, operations[i].size() - 2));
        if (c == 'I') ms.insert(n);
        if (c == 'D') {
            if (ms.empty()) continue;
            if (n == 1) {
                it = ms.end();
                ms.erase(--it);
            }
            else if (n == -1) {
                it = ms.begin();
                ms.erase(it);
            }
        }
    }
    if (ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        it = ms.begin();
        it2 = ms.end();
        answer.push_back(*(--it2));
        answer.push_back(*it);
    }
    return answer;
}