#include <bits/stdc++.h>
using namespace std;

int answer;
int M, N;
const int MN = 1001;

int tomato[MN][MN];
int dist[MN][MN];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ni = x + di[d];
            int nj = y + dj[d];
            if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                if (tomato[ni][nj] == 0) {
                    dist[ni][nj] = dist[x][y] + 1;
                    tomato[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
    }
}

int main(void) {
    bool check = true;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) q.push({i, j});
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) {
                check = false;
            }
        }
    }

    if (check) {  // 저장될 때부터 모든 토마토가 익은 상태
        cout << 0 << '\n';
        return 0;
    } 

    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) {  // 토마토가 모두 익지는 못한 상황
                cout << -1 << '\n';
                return 0;
            }
            answer = max(answer, dist[i][j]);
        }
    }
    cout << answer << '\n';
    return 0; 
}