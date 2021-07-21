#include <bits/stdc++.h>
using namespace std;

const int MN = 301;
int di[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dj[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool visited[MN][MN];
int dist[MN][MN];

int bfs(int sx, int sy, int ex, int ey, int size) {
    int answer = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
    
        if (x == ex && y == ey) break;

        for (int d = 0; d < 8; d++) {
            int ni = x + di[d];
            int nj = y + dj[d];
            if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                if (!visited[ni][nj]) {
                    q.push(make_pair(ni, nj));
                    visited[ni][nj] = true;
                    dist[ni][nj] = dist[x][y] + 1;
                }
            }
        }
    }

    return dist[ex][ey];
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int T;  cin >> T;
    
    while (T--) {
        int I;  cin >> I;
        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;

        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        
        if (start_x == end_x && start_y == end_y) cout << 0 << '\n';
        else cout << bfs(start_x, start_y, end_x, end_y, I) << '\n';
    }

    return 0;
}