#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;

vector<int> graph[MN];
bool visited[MN];
int cnt;

void dfs (int x) {
    visited[x] = true;

    for (int i : graph[x]) {
        if (!visited[i]) dfs(i);
    }
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int N, M;  cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;  cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
}