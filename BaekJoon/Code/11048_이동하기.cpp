#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
const int MAX = 1001;
int moveX[3] = {-1, -1, 0};
int moveY[3] = {-1, 0, -1};
int candy[MAX][MAX];
long long dp[MAX][MAX];

void Input() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> candy[i][j];
        }
    }
}

void Solution() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            long long maxCandy = 0;
            for (int d = 0; d < 3; d++) {
                int y = i + moveY[d];
                int x = j + moveX[d];
                maxCandy = max(maxCandy, dp[y][x]);
            }
            dp[i][j] = candy[i][j] + maxCandy;
        }
    }
}

void Solve() {
    Input();
    Solution();
    cout << dp[N][M] << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

	Solve();
	return 0;
}    
