#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define P pair<int, int>
using namespace std;
const int MN = 801;
const int INF = 123456789; // INF를 너무 크게 하면 Overflow 발생해서 '틀렸습니다' 평가 되었음

int N, E, V1, V2;
int dist_S[MN];
int dist_V1[MN];
int dist_V2[MN];
vector<P> graph[MN];

void Dijkstra(int start, int dist[MN]) {
    fill(dist, dist + N + 1, INF);

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, start});
    dist[start] = 0;

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

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;  cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    cin >> V1 >> V2;

    Dijkstra(1, dist_S);
    Dijkstra(V1, dist_V1);
    Dijkstra(V2, dist_V2);

    int answer = min(dist_S[V1] + dist_V1[V2] + dist_V2[N], dist_S[V2] + dist_V2[V1] + dist_V1[N]);
    answer >= INF ? (cout << -1 << '\n') : (cout << answer << '\n');

    return 0;
}