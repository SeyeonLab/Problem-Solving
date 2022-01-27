#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
int N, M;
int dist[MN][MN];
int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};
bool only_check;
bool visited[2][MN][MN];  // 벽을 부수고 방문한 경우, 벽을 부수지 않고 방문한 경우
string graph[MN];

void bfs(int a, int b) {
    queue<pair<pair<int, int>, bool>> q;
    q.push({{a, b}, false});
    visited[0][a][b] = true;

    while (!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        bool check = q.front().second;
        q.pop();

        if (i == N-1 && j == M-1) return;

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                if (!visited[check][ni][nj] && graph[ni][nj] == '0') {
                    q.push({{ni, nj}, check});
                    visited[check][ni][nj] = true;
                    dist[ni][nj] = dist[i][j] + 1;
                }

                if (!visited[check][ni][nj] && graph[ni][nj] == '1' && !check) {
                    q.push({{ni, nj}, true});
                    visited[check][ni][nj] = true;
                    dist[ni][nj] = dist[i][j] + 1;
                }
            }
        }
    }

    cout << -1 << '\n';
    exit(0);
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> graph[i];
    }
    
    bfs(0, 0);
    cout << dist[N-1][M-1] + 1;

    exit(0);
}