#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 301;
int N;
long long dp[MAX];
long long score[MAX];

int main(void) {
	ios::sync_with_stdio(false);  cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}

	for (int i = 1; i <= N; i++) {
		if (i == 1) dp[i] = score[i];
		else if (i == 2) dp[i] = score[i] + score[i - 1];
		else {
			dp[i] = score[i] + max(score[i - 1] + dp[i - 3], dp[i - 2]);
		}
	}
	cout << dp[N] << '\n';

	return 0;
}
