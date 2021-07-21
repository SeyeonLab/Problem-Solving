#include <bits/stdc++.h>

using namespace std;

const int MN = 1000001;
int answer;
int F, S, G, U, D;

bool visited[MN];
int dist[MN];
vector<int> graph[MN];
queue<int> q;

void bfs (int start) {
    q.push(start);
    visited[start] = true;
    int button[2] = {U, -D};

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        if (x == G) break;

        for (int d = 0; d < 2; d++) {
            int up_down = x + button[d];
            if (up_down >= 1 && up_down <= F) {
                if (!visited[up_down]) {  
                    q.push(up_down);
                    dist[up_down] = dist[x] + 1;
                    visited[up_down] = true;
                }
            }
        }
    }
}

int main(void) {
    cin >> F >> S >> G >> U >> D;

    bfs(S);

    if (dist[G] == 0 && S != G) cout << "use the stairs";
    else cout << dist[G];

    return 0;
}