#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
int cnt;
bool visited[MN];
vector<int> graph[MN];

void dfs(int start) {
    visited[start] = true;

    for (int i : graph[start]) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    cout << cnt;
    return 0;
}