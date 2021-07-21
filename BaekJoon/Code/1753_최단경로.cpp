#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define P pair<int, int>

const int MN = 20001;
const int INF = 1e9;
int dist[MN];
vector<P> graph[MN];  // 인접 리스트 선언

/*
struct edge {
    int v, w;
};

struct cmp {
    bool operator()(edge A, edge B) {
        return A.w > B.w;
    };
};
*/

int main(void) {
    int V, E, K;  cin >> V >> E >> K;
    
    for (int i = 0; i < E; i++) {
        int u, v, w;  cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    fill(dist, dist+V+1, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, K});
    dist[K] = 0;
    
    while (!pq.empty()) {
        P top = pq.top();  
        pq.pop();
        
        int w = top.first;
        int v = top.second;

        if (dist[v] < w) continue;

        for (P edge : graph[v]) {
            int cost = edge.first;
            int next = edge.second;

            if (dist[next] > dist[v] + cost) {
                dist[next] = dist[v] + cost;
                pq.push({dist[next], next});
            }
        }        
    }
    
    for (int i = 1; i <= V; i++)
        dist[i] == INF ? (cout << "INF" << '\n') : (cout << dist[i] << '\n');

    return 0;
}