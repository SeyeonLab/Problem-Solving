#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

    set<int> set1, set2;
    int A, B, cnt = 0;
    cin >> A >> B;

    for (int i = 0; i < A; i++) {
        int num;  cin >> num;
        set1.insert(num);
        cnt++;
    }

    for (int i = 0; i < B; i++) {
        int num;  cin >> num;
        set2.insert(num);
        cnt++;
    }

    for (auto i : set2) {
        if (set1.count(i) != 0) cnt--;
    }

    for (auto i : set1) {
        if (set2.count(i) != 0) cnt--;
    }
    
    cout << cnt << '\n';

    return 0;
}