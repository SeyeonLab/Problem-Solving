#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000009;
const int MAX = 100001;
long long dp[MAX][4];

void Solve() {
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1; // 1: (1), 2: (2), 3: (1+2) (2+1) (3)
	for (int i = 4; i < MAX; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}
}

int main(void) {
	ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

	Solve();
	int T; cin >> T;
	
	while (T--) {
		int N;  cin >> N;
		cout << (dp[N][1] + dp[N][2] + dp[N][3]) % MOD << '\n';
	}

	return 0;
}    
