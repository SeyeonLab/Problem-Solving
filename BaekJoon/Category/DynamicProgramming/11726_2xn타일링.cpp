#include <iostream>
using namespace std;

const int MAX = 1001;
int N;
long long dp[MAX];

int main(void) {
	ios::sync_with_stdio(false);  cin.tie(NULL);

	cin >> N;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 2] % 10007 + dp[i - 1] % 10007;
		dp[i] %= 10007;
	}
	cout << dp[N] << '\n';

	return 0;
}
