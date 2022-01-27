#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
const int MAX = 1001;
const int MOD = 10007;
int dp[MAX][MAX];

void Init() {
    for (int i = 0; i < MAX; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
}

void Input() {
    cin >> N >> K;
}

void Output() {
    cout << dp[N][K] % MOD << '\n';
}

void Solution() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(i, K); j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
}

void Solve() {
    Init();
    Input();
    Solution();
    Output();
}

int main(void) {
	ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

	Solve();
	return 0;
}    
