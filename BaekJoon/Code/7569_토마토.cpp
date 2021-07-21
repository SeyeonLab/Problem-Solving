#include <bits/stdc++.h>
using namespace std;

int answer;
int M, N, H;
const int MNH = 101;

int tomato[MNH][MNH][MNH];
int dist[MNH][MNH][MNH];
bool visited[MNH][MNH][MNH];
int dh[6] = {0, 0, 0, 0, -1, 1};
int dn[6] = {0, 0, 1, -1, 0, 0};
int dm[6] = {1, -1, 0, 0, 0, 0};
queue<pair<int, pair<int, int>>> q;

bool range_check(int a, int b, int c) {
    return (a >= 0 && a < H && b >= 0 && b < N && c >= 0 && c < M);
}

void bfs() {
    while (!q.empty()) {
        int h = q.front().first;
        int n = q.front().second.first;
        int m = q.front().second.second;
        q.pop();

        for (int d = 0; d < 6; d++) {
            int nh = h + dh[d];
            int nn = n + dn[d];
            int nm = m + dm[d];
            if (range_check(nh, nn, nm)) {
                if (tomato[nh][nn][nm] == 0) {
                    dist[nh][nn][nm] = dist[h][n][m] + 1;
                    tomato[nh][nn][nm] = 1;
                    q.push({nh, {nn, nm}});
                }
            }
        }
    }
}

int main(void) {
    bool check = true;
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) q.push({i, {j, k}});
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[i][j][k] == 0) {
                    check = false;
                }
            }
        }
    }

    if (check) {  // 저장될 때부터 모든 토마토가 익은 상태
        cout << 0 << '\n';
        return 0;
    } 

    bfs();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[i][j][k] == 0) {  // 토마토가 모두 익지는 못한 상황
                    cout << -1 << '\n';
                    return 0;
                }
                answer = max(answer, dist[i][j][k]);
            }
        }
    }
    cout << answer << '\n';
    return 0; 
}