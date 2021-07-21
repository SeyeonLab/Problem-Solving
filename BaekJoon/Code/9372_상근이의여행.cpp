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

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    
    int T;  cin >> T;
    while (T--) {
        cin >> N >> M;
        int answer = 0;
        init();

        for (int i = 0; i < M; i++) {
            int a, b;  cin >> a >> b;
            if (find(a) != find(b)) {
                unite(a, b);
                answer++;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}