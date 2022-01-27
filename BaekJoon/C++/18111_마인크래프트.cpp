#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e9;
const int MN = 501;

int N, M, B;
int place[MN][MN];
int mymin = 1001;
int mymax = -1;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> place[i][j];
            mymin = min(mymin, place[i][j]);
            mymax = max(mymax, place[i][j]);
        }
    }

    int time = MAX;
    int height = 0;

    for (int i = mymin; i <= mymax; i++) {
        int build = 0;
        int remove = 0;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int temp = i - place[j][k];

                if (temp < 0) remove += temp * -1;
                else build += temp;
            }
        }
        
        if (build <= remove + B) {
            int temp = build + remove * 2;
            if (time > temp) {
                time = temp;
                height = i;
            }

            if (temp == time) {
                if (height < i) height = i;
            }
        }
    }

    cout << time << ' ' << height << '\n';
}