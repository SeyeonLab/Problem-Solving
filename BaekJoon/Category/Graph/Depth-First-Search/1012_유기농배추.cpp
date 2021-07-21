#include <bits/stdc++.h>

using namespace std;

const int MN = 51;
int cnt;
bool visited[MN][MN];
int graph[MN][MN];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

void dfs(int a, int b) {
    visited[a][b] = true;

    for (int d = 0; d < 4; d++) {
        int ni = a + di[d];
        int nj = b + dj[d];
        if (ni >= 0 && ni < MN && nj >= 0 && nj < MN) {
            if (!visited[ni][nj] && graph[ni][nj] > 0) dfs(ni, nj);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int T;  cin >> T;
    
    while (T--) {
        int M, N, K;  cin >> M >> N >> K;
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));;

        cnt = 0;

        for (int i = 0; i < K; i++) {
            int X, Y; cin >> X >> Y;
            graph[Y][X] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && graph[i][j] > 0) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}