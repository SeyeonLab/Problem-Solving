#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    string s;
    vector<string> v;
    cin >> s;
    while (!s.empty()) {
        v.push_back(s);
        s = s.substr(1, s.size());
    }
    sort(v.begin(), v.end());

    vector<string>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << '\n';
    }
}