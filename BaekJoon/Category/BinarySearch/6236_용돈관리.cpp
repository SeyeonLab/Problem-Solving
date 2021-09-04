#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int money[100001];

bool withdraw (int cash) {
    int cnt = 1;
    int now = cash;
    
    for (int i = 0; i < N; i++) {
        if (now >= money[i]) {
            now -= money[i];
        }
        else {
            now = cash;
            now -= money[i];
            cnt++;
        }
    }
    return M >= cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;

    int low = 0, high = 0, result = 0;

    for (int i = 0; i < N; i++) {
        cin >> money[i];
        low = max(low, money[i]);
        high += money[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (withdraw(mid)) {
            result = mid;
            high = mid - 1;            
        }
        else {
            low = mid + 1;
        }
    }

    cout << result << '\n';
    
    return 0;
}