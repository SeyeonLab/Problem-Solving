#include <iostream>

using namespace std;
const int MN = 1000001;

int parent[MN], level[MN];
int N, M;
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

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    cin >> N >> M;
    init();

    for (int i = 0; i < M; i++) {
        int q, a, b;  cin >> q >> a >> b;
        if (q) cout << (find(a) == find(b) ? "YES\n" : "NO\n");  // find(a) == find(b) 가 참이면, 같은 집합
        else unite(a, b);
    }

    return 0;
}