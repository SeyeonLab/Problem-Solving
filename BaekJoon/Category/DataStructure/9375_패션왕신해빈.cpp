#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

    int T;  cin >> T;
    while (T--) {
        map<string, int> m;
        int n;  cin >> n;
        for (int i = 0; i < n; i++) {
            string name, kind;  cin >> name >> kind;
            if (m.find(kind) == m.end())  m[kind] = 1;
            else  m[kind]++;
        }
        
        int answer = 1;
        for (auto it : m)  answer *= (it.second + 1);
        answer--;
        cout << answer << '\n';
    }

    return 0;
}