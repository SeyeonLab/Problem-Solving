#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 501;

int M, N;
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
int m[MAX][MAX];
int DP[MAX][MAX];

void Input() {
	ios::sync_with_stdio(false);  
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
            DP[i][j] = -1;
		}
	}
}

int DFS(int a, int b) {
    if (a == M - 1 && b == N - 1) return 1;
    if (DP[a][b] != -1) return DP[a][b];

    DP[a][b] = 0;

    for (int i = 0; i < 4; i++) {
        int ni = a + di[i];
        int nj = b + dj[i];
        if (ni >= 0 && nj >= 0 && ni < M && nj < N) {
            if (m[ni][nj] < m[a][b]) {
                DP[a][b] += DFS(ni, nj);
            }
        }
    }

    return DP[a][b];
}

void Solution() {
    cout << DFS(0, 0) << '\n';
}

void Solve() {
	Input();
    Solution();
}

int main(void) {
	Solve();
	return 0;
}
