#include <iostream>
using namespace std;

const int MAX = 501;
int N;
int max_num = 0;
int arr[MAX];
int DP[MAX];

void Input() {
    ios::sync_with_stdio(false);
    int n1, n2;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n1 >> n2;
        arr[n1] = n2;
        DP[n1] = 1;
        max_num = max(max_num, n2);
    }
}

void Solution() {
    int answer = 0;
    for (int i = 1; i <= max_num; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j])
                DP[i] = max(DP[i], DP[j] + 1);
        }
        answer = max(answer, DP[i]);
    }
    cout << N - answer << '\n';
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    Solve();
    return 0;
}