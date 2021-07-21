#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
int cnt;
bool visited[MN][MN];
int graph[MN][MN];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j) {
    visited[i][j] = true;

    for (int d = 0; d < 8; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni >= 0 && ni < MN && nj >= 0 && nj < MN) {
            if (!visited[ni][nj] && graph[ni][nj] > 0) {
                dfs(ni, nj);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int w, h;  
    while (1) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));
        cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {   
                cin >> graph[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
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