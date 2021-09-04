#include <iostream>
#include <algorithm>
using namespace std;

int N;
const int MAX = 101;
int board[MAX][MAX];
long long DP[MAX][MAX];

void Input() {
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    
    DP[1][1] = 1;
}

void Output() {
    cout << DP[N][N] << '\n';
}

void Solution() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int jumpY = i + board[i][j];
            int jumpX = j + board[i][j];

            if (jumpX <= N && board[i][j] > 0) DP[i][jumpX] += DP[i][j];
            if (jumpY <= N && board[i][j] > 0) DP[jumpY][j] += DP[i][j];
        }
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
