#include <bits/stdc++.h>
using namespace std;

const int MN = 101;
int answer;
int a, b;
int dist[MN];
bool visited[MN];
vector<int> graph[MN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == b) {
            answer = dist[x];
            return;
        }

        for (int i : graph[x]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[x] + 1;
            }   
        }
    }
    answer = -1;
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    
    int n, m;
    cin >> n >> a >> b >> m;

    for (int i = 0; i < m; i++) {
        int x, y;  cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(a);
    cout << answer;

    return 0;
}