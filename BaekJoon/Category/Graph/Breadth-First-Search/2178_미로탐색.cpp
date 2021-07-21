#include <bits/stdc++.h>
using namespace std;

const int MN = 101;
int N, M;
int answer;
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
bool visited[MN][MN];
map<pair<int, int>, int> dist;
string graph[MN];

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = true;

    while (!q.empty()) {
        pair<int, int> x = q.front();
        q.pop();

        if (x.first == N-1 && x.second == M-1) {
            answer = dist[x] + 1;
        }

        for (int d = 0; d < 4; d++) {
            int ni = x.first + di[d];
            int nj = x.second + dj[d];
            if (ni >= 0 && ni <= N && nj >= 0 && nj <= M) {
                if (!visited[ni][nj] && graph[ni][nj] == '1') {
                    pair<int, int> p = make_pair(ni, nj);
                    q.push(p);
                    visited[ni][nj] = true;
                    dist[p] = dist[x] + 1;
                }
            }
        }
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> graph[i];
    bfs(0, 0);

    cout << answer;

    return 0;
}