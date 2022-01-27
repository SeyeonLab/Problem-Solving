#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000001;
int N;
int arr[MAX];
vector<int> DP;

void Input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void Solution() {
    for (int i = 0; i < N; i++) {
        if (DP.empty() || DP.back() < arr[i])
            DP.push_back(arr[i]);
        else {
            auto it = lower_bound(DP.begin(), DP.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout << DP.size() << '\n';
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    Solve();
    return 0;
}