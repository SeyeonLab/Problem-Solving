#include <iostream>
#include <algorithm>

using namespace std;
const int NN = 10001;
const int MM = 100001;

struct edge {
    int u, v, w;
};

int N, M;
int parent[NN], level[NN];
edge arr[MM];

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

bool cmp(const edge &A, const edge &B) {
    return A.w < B.w;
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    
    cin >> N >> M;
    init();

    for (int i = 0; i < M; i++) {
        cin >> arr[i].u >> arr[i].v >> arr[i].w;
    }

    sort(arr, arr + M, cmp);

    int cnt = 0, sum = 0;
    for (int i = 0; i < M; i++) {
        int u = arr[i].u;
        int v = arr[i].v;
        int w = arr[i].w;

        if (cnt == N - 1) break;        
        if (find(u) != find(v)) {
            unite(u, v);
            sum += w;
            cnt++;
        }
    }

    cout << sum;

    return 0;
}