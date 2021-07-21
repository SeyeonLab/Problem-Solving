#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 101;
const int INF = 1e9;
int floyd[MN][MN];

int main(void) {
    int N;  cin >> N;

    fill(&floyd[0][0], &floyd[MN][MN], INF);
    for (int i = 0; i <= N; i++)
        floyd[i][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> floyd[i][j];
        }
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
            cout << (floyd[i][j] == INF ? 0 : floyd[i][j]) << ' ';
        }
        cout << '\n';
    }
}