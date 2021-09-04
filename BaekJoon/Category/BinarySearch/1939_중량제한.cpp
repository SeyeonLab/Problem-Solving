#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 100000 + 1;
int N, M;
int f1, f2;
bool visited[MAX];
vector<pair<int, int>> route[MAX];

bool bfs(int cost) {
    queue<int> q;
    q.push(f1);
    visited[f1] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == f2) return true;

        for (int i = 0; i < route[curr].size(); i++) {
            int next = route[curr][i].second;
            int nextCost = route[curr][i].first;

            if (!visited[next] && cost <= nextCost) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int maxW = 0;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, W;

        cin >> A >> B >> W;
        route[A].push_back({W, B});
        route[B].push_back({W, A});
        maxW = max(maxW, W);
    }

    cin >> f1 >> f2;

    int low = 0, high = maxW;
    
    while (low <= high) {
        int mid = (low + high) / 2;

        memset(visited, false, sizeof(visited));
        if (bfs(mid)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << high << '\n';
}