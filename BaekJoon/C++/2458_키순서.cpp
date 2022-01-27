#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 501;
const int INF = 1e9;
int floyd[MN][MN];
int check[MN];
int answer;

int main(void) {
    int N, M;  cin >> N >> M;

    for (int i = 0; i <= N; i++)
        floyd[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int a, b;  cin >> a >> b;
        floyd[a][b] = 1;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                if (floyd[i][k] > 0 && floyd[k][j] > 0) {
                    floyd[i][j] = 1;
                }
            }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (floyd[i][j] > 0) check[i]++;
            if (floyd[j][i] > 0) check[i]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (check[i] == N-1) answer++;
    }
    cout << answer;
}