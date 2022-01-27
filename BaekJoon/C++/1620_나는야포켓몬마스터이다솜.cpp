#include <bits/stdc++.h>
#include <cctype>

using namespace std;

unordered_map<string, int> info;
vector<string> answer;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int n, m;  cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        string name;  cin >> name;
        info.insert({name, i});
        answer.push_back(name);
    }

    while (m--) {
        string p;  cin >> p;
        if (isalpha(p.front())) {
            int res;
            res = info.find(p)->second;
            cout << res << '\n';
        }
        else {
            string res;
            res = answer[stoi(p) - 1];
            cout << res << '\n';
        }
    }
    return 0;
}