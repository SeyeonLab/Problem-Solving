#include <iostream>
#include <cctype>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    map<char, int> m;
    string s;   cin >> s;
    for (int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
    }
    
    for (string::iterator it = s.begin(); it != s.end(); it++) {
        m[*it]++;
    }

    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
        });

    int max;
    max = v[0].second;
    if (max == v[1].second)
        cout << '?' << '\n';
    else   
        cout << v[0].first << '\n';
}