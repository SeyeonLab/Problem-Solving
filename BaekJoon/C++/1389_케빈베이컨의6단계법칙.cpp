#include <bits/stdc++.h>
using namespace std;

const int MN = 101;
int min_kb = 1000001;
int dist[MN];
bool visited[MN];
vector<int> friends[MN];
vector<int> kevinbacon;

int bfs(int start) {
    queue<int> q;
    int cnt = 0;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cnt += dist[x];

        for (int i : friends[x]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[x] + 1;
            }   
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    
    int answer;
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;  cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    kevinbacon.push_back(0);
    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        kevinbacon.push_back(bfs(i));
    }

    for (int i = 1; i <= N; i++) {
        if (min_kb > kevinbacon[i]) {
            answer = i;
            min_kb = min(min_kb, kevinbacon[i]);
        }
    }
    cout << answer;

    return 0;
}