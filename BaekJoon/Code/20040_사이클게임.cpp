#include <iostream>
#include <algorithm>

using namespace std;
const int NN = 500001;
const int MM = 1000001;

int parent[NN], level[NN];

void init(int n) {
    for (int i = 0; i < n; i++)  parent[i] = i;
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;  // 서로 같은 집합
    parent[y] = x;
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int n, m;  cin >> n >> m;
    init(n);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        if (find(u) != find(v)) {
            unite(u, v);
        }
        else {
            cout << i;
            return 0;
        }
    }
    cout << 0;

    return 0;
}