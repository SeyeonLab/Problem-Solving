#include <bits/stdc++.h>
using namespace std;

int answer1, answer2, answer3;
int M, N;
const int MN = 20001;
bool visited[MN];
int dist[MN];
vector<int> barn[MN];  // 헛간 인접리스트
queue<int> q;

void bfs (int s) {
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto it : barn[x]) {
            if (!visited[it]) {
                q.push(it);
                visited[it] = true;
                dist[it] = dist[x] + 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int start, end;  cin >> start >> end;
        barn[start].push_back(end);
        barn[end].push_back(start);
    }
    bfs(1);

    for (int i = 1; i <= N; i++) {
        if (answer2 < dist[i]) {
            answer1 = i;
            answer2 = dist[i];
        }
    }

    for (int i = answer1; i <= N; i++) {
        if (dist[i] == answer2) answer3++;
    }

    cout << answer1 << ' ' << answer2 << ' ' << answer3 << '\n';

    return 0;
}