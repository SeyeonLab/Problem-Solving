#include <bits/stdc++.h>
using namespace std;

int answer;
int N;
const int MN = 101;

vector<int> graph[MN];
bool safe_area[MN][MN];
bool visited[MN][MN];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

void dfs(int i, int j) {
    visited[i][j] = true;

    for (int d = 0; d < 4; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
            if (!visited[ni][nj] && safe_area[ni][nj]) {
                dfs(ni, nj);
            }
        }
    }
}

int main(void) {
    int count = 0, max_height = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int height;  cin >> height;
            max_height = max(max_height, height);
            graph[i].push_back(height);
        }
    }

    for (int rain = 0; rain <= max_height; rain++) {
        count = 0;
        memset(safe_area, false, sizeof(safe_area));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (graph[i][j] > rain) {
                    safe_area[i][j] = true;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && safe_area[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        answer = max(count, answer);
    }
    cout << answer << '\n';

    return 0;
}
