#include <iostream>
using namespace std;

const int MAX = 41;
int N, M;
int answer = 1;
int dp[MAX];

int main(void) {
	ios::sync_with_stdio(false);  cin.tie(NULL);

	cin >> N >> M;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];                
	}

	int tmp = 0;
	for (int i = 0; i < M; i++) {
		int vip;  cin >> vip;
		answer *= dp[vip - tmp - 1];
		tmp = vip;
	}
	answer *= dp[N - tmp];

	cout << answer << '\n';

	return 0;
}
