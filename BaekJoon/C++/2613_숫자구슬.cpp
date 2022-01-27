#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
const int inf = 1e9;

int N, M;
int marble[301];

bool possible(int n) {
    int groupCnt = 0;
    int m = 1;
    for (int i = 0; i < N; i++) {
        if (marble[i] > n)
            return false;

        if (groupCnt + marble[i] <= n)
            groupCnt += marble[i];
        else {
            m++;
            groupCnt = marble[i];
        }
    }

    if (m <= M)
        return true;
    else
        return false;
}

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> marble[i];
    }

    int low = 0;
    int high = N * 100;
    int answer = inf;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (possible(mid)) {
            high = mid - 1;
            if (mid < answer)
                answer = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';

    int groupCnt = 0;
    int m = 1;
    vector<int> marbleCnt;
    marbleCnt.push_back(0);

    for (int i = 0; i < N; i++) {
        if (groupCnt + marble[i] <= answer) {
            groupCnt += marble[i];
            marbleCnt.back()++;
        }
        else {
            m++;
            groupCnt = marble[i];
            marbleCnt.push_back(1);
        }
    }

    int diff = M - m;
    for (int i = 0; i < m; i++) {
        if (marbleCnt[i] == 1)
            cout << 1 << ' ';
        else {
            while (marbleCnt[i] >= 2 && diff >= 1) {
                cout << 1 << ' ';
                marbleCnt[i]--;
                diff--;
            }
            cout << marbleCnt[i] << ' ';
        }
    }

    return 0;
}