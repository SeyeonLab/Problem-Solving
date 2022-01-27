#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define P pair<int, int>
using namespace std;
const int MN = 1001;
const int INF = 1e9; // INF를 너무 크게 하면 Overflow 발생해서 '틀렸습니다' 평가 되었음

int N, M, Start, End;
int dist[MN];
vector<P> graph[MN];

void Dijkstra() {
    fill(dist, dist + N + 1, INF);

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, Start});
    dist[Start] = 0;

    while (!pq.empty()) {
        P top = pq.top();  pq.pop();
        int weight = top.first;
        int curr = top.second;

        if (dist[curr] < weight) continue;

        for (P edge : graph[curr]) {
            int cost = edge.first;
            int next = edge.second;
            
            if (dist[next] > dist[curr] + cost) {
                dist[next] = dist[curr] + cost;
                pq.push({dist[next], next});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        int w;
        
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    cin >> Start >> End;

    Dijkstra();
    cout << dist[End];

    return 0;
}