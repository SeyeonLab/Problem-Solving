#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
int N;

void Solution() {
    vector<int> DP;
    for (int i = 0; i < N; i++) {
        int num;  cin >> num;
        if (DP.empty() || DP.back() < num)
            DP.push_back(num);
        else {
            auto it = lower_bound(DP.begin(), DP.end(), num);
            *it = num;
        }
    }
    cout << DP.size() << '\n';
}

void Solve() {
    ios::sync_with_stdio(false);

    while (cin >> N) {
        Solution();
    }
}

int main(void) {
    Solve();
    return 0;
}