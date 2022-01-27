#include <iostream>

using namespace std;
const int MN = 201;

int parent[MN], level[MN];
int N, M;
bool check;

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
    int city[N + 1][N + 1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                if (find(i) != find(j)) {
                    unite(i, j);
                }
            }
        }
    }
    
    int temp, num;
    cin >> num;
    temp = find(num);

    for (int i = 1; i < M; i++) {
        cin >> num;
        if (temp != find(num))
            check = true;
            
        temp = find(num);
    }

    if (check) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}