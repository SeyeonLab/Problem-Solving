#include <iostream>
using namespace std;

const int MAX = 1001;
int DP[MAX];
int arr[MAX];
int N;

void Input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void Solution() {
    int answer = 0;
    for (int i = 0; i < N; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j])
                DP[i] = max(DP[i], DP[j] + 1);
        }
        answer = max(answer, DP[i]);
    }
    cout << answer << '\n';
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    Solve();
    return 0;
}