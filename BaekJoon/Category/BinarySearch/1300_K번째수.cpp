#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    int low = 1;
    int high = K;
    int answer = 0;

    while (low <= high) {
        long long cnt = 0;
        int mid = (low + high) / 2;

        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }

        if (cnt < K) {
            low = mid + 1;
        }
        else {
            answer = mid;
            high = mid - 1;
        }
    }
    cout << answer;
}