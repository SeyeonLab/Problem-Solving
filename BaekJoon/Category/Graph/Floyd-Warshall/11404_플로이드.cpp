#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 101;
const int INF = 1e9;
int floyd[MN][MN];

int main(void) {
    int N, M;  cin >> N >> M;

    fill(&floyd[0][0], &floyd[MN-1][MN-1], INF);
    for (int i = 0; i <= N; i++)
        floyd[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int u, v, w;  cin >> u >> v >> w;
        floyd[u][v] = min(floyd[u][v], w);  // 여러 경로가 있을 수 있기 때문에 최소 값만 취함
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (floyd[i][j] == INF ? 0 : floyd[i][j]) << ' ';
        }
        cout << '\n';
    }
}