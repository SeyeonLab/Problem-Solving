#include <bits/stdc++.h>
using namespace std;

const int MN = 51;
int answer;
int cnt;
int dist[MN];
bool visited[MN];
vector<int> friends[MN];
string graph[MN];

void bfs(int man) {
    queue<int> q;
    q.push(man);
    visited[man] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (dist[x] <= 2) cnt++;

        for (int i : friends[x]) {
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
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> graph[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 'Y') {
                friends[i].push_back(j);
                friends[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        if (!visited[i]) bfs(i);
        answer = max(cnt, answer);
    }
    cout << answer - 1;

    return 0;
}