#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MMM 1e9
using namespace std;
#define P pair<int, int>
const int MN = 1001;
const int INF = 1e9;

int N, M, X;
int distParty[MN];
int distHome[MN];
vector<P> goParty[MN];
vector<P> goHome[MN];

void Dijkstra(int dist[MN], vector<P> graph[MN]) {
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, X});
    dist[X] = 0;

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

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int u, v, w;  cin >> u >> v >> w;
        goHome[u].push_back({w, v});
        goParty[v].push_back({w, u});
    }
    fill(distParty, distParty + N + 1, INF);
    fill(distHome, distHome + N + 1, INF);

    Dijkstra(distHome, goHome);
    Dijkstra(distParty, goParty);

    int answer = 0;
    for (int i = 1; i <= N; i++) answer = max(answer, distParty[i] + distHome[i]);
    cout << answer;
    cout << MMM << '\n';
    return 0;
}