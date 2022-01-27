#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

int N, M, V; 
bool visited[MAX];
vector<int> graph[MAX];

void dfs(int start) {
    stack<int> s;
    s.push(start);
    
    while (!s.empty()) {
        int x = s.top();
        s.pop();
        if (visited[x]) continue;

        visited[x] = true;
        cout << x << ' ';

        sort(graph[x].begin(), graph[x].end(), greater<int>());
        for (int i : graph[x]) {
            if (!visited[i]) {
                s.push(i);
            }
        }
    }
    cout << '\n';
}

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (visited[x]) continue;

        visited[x] = true;
        cout << x << ' ';

        sort(graph[x].begin(), graph[x].end());
        for (int i : graph[x]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

    cin >> N >> M >> V;

    for (int i = 0 ; i < M; i++) {
        int start, end;  
        cin >> start >> end;
        
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    dfs(V);
    memset(visited, 0, 1001);
    bfs(V);

    return 0;
}
