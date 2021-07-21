#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int T;  cin >> T;

    while (T--) {
        multiset<int> ms;
        multiset<int>::iterator it, it2;
        int k;  cin >> k;
        for (int i = 0; i < k; ++i) {
            char c; int n;
            cin >> c >> n;
            if (c == 'I') {
                ms.insert(n);
            }   
            else if (c == 'D') {
                if (ms.empty()) continue;
                if (n == 1) {
                    it = ms.end();
                    it--;
                    ms.erase(it);
                }
                else if (n == -1) {
                    it = ms.begin();
                    ms.erase(it);
                }
            }         
        }
        if (ms.empty()) cout << "EMPTY" << '\n';
        else {
            it = ms.begin();
            it2 = ms.end();
            it2--;
            cout << *it2 << ' ' << *it << '\n';
        }
    }

    return 0;
}