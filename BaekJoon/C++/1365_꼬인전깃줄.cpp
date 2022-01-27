#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
int N;
int arr[MAX];

void Input() {
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void Solution() {
    vector<int> DP;
    for (int i = 1; i <= N; i++) {
        if (DP.empty() || DP.back() < arr[i])
            DP.push_back(arr[i]);
        else {
            auto it = lower_bound(DP.begin(), DP.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout << N - DP.size() << '\n';
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    Solve();
    return 0;
}