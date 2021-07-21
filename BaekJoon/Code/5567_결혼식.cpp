#include <bits/stdc++.h>
using namespace std;

const int MN = 501;
int answer;
int dist[MN];
bool visited[MN];
vector<int> graph[MN];

void bfs(int id) {
    queue<int> q;
    q.push(id);
    visited[id] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (dist[x] <= 2) answer++;

        for (int i : graph[x]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[x] + 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int n, m;  cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;  cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    cout << answer - 1;
    return 0;
}