#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

    int size = 0;
    map<string, int> m;

    cout.precision(4);
    cout << fixed;

    string tree;
    while (getline(cin, tree)) {
        m[tree]++;
        size++;
    }

    for (auto it : m) cout << it.first << ' ' << (float) (it.second * 100) / size  << '\n';
    return 0;
}