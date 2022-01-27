#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
long long budget[10001];

bool possible (long long limit) {
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        if (budget[i] >= limit) sum += limit;
        else sum += budget[i];
    }
            
    if (sum <= M)
        return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    long long low = 1, high = 0, result = 0, sum = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> budget[i];
        sum += budget[i];
        high = max(high, budget[i]);
    }
    cin >> M;

    if (sum <= M) {
        cout << high << '\n';
        return 0;
    }
    
    while (low <= high) {
        long long mid = (low + high) / 2;

        if (possible(mid)) {
            result = max(result, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    
    cout << result << '\n';
    return 0;
}