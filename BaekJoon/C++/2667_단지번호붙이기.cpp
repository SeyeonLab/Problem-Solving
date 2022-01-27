#include <bits/stdc++.h>

using namespace std;
const int MN = 26;
int N;
bool visited[MN][MN];
string graph[MN];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int dfs(int a, int b) {
    visited[a][b] = true;
    int cnt = 1;

    for (int d = 0; d < 4; d++) {
        int ni = a + di[d];
        int nj = b + dj[d];
        if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
            if (!visited[ni][nj] && graph[ni][nj] == '1') {
                cnt += dfs(ni, nj);
            }
        }
    }

    return cnt;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> graph[i];
    }

    int count = 0;
    vector<int> answer;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && graph[i][j] == '1') {
                answer.push_back(dfs(i, j));
                count++;
            }
        }
    }
    sort(answer.begin(), answer.end());

    cout << count << '\n';
    for (auto i : answer) cout << i << '\n';

    return 0;
}