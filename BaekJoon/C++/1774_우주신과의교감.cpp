#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int MN = 1001;

struct e {
    int u, v;
    double w;
};

struct space {
    int X, Y;
};

int N, M;
int parent[MN], level[MN];
space arr[MN];
vector<e> edge;

void init() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        level[i] = 1;
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;  // 서로 같은 집합
    if (level[x] < level[y])
        swap(x, y);  // x가 더 길게 만듦

    parent[y] = x;

    if (level[x] == level[y])
        level[x]++;
}

bool cmp(const e &A, const e &B) {
    return A.w < B.w;
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    
    cin >> N >> M;
    init();

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].X >> arr[i].Y;
        for (int j = 1; j < i; j++) {
            edge.push_back({i, j, sqrt(pow((arr[i].X - arr[j].X), 2) + pow((arr[i].Y - arr[j].Y), 2))});
        }
    }

    for (int i = 0; i < M; i++) {
        int c1, c2;  cin >> c1 >> c2;
        unite(c1, c2);
    }

    sort(edge.begin(), edge.end(), cmp);

    double sum = 0;
    for (int i = 0; i < edge.size(); i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        double w = edge[i].w;

        if (find(u) != find(v)) {
            unite(u, v);
            sum += w;
        }
    }
    cout.precision(2);
    cout << fixed << sum;

    return 0;
}