#include <iostream>
#include <algorithm>
using namespace std;

int N;
const int MAX = 1000001;
long long DP[MAX];

void Input() {
    cin >> N;
}

void Output() {
    cout << DP[N] << '\n';
}

void Solution() {
    for (int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + 1;
        if(i % 2 == 0) DP[i] = min(DP[i / 2] + 1, DP[i]);
        if(i % 3 == 0) DP[i] = min(DP[i / 3] + 1, DP[i]);
    }
}

void Solve() {
    Input();
    Solution();
    Output();
}

int main(void) {
	ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

	Solve();
	return 0;
}    
