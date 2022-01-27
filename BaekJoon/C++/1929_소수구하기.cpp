#include <iostream>

using namespace std;
bool check[1000001];

int main(void) {
    int M, N;
    cin >> M >> N;

    check[0] = true; check[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (check[i]) continue;
        for (int p = i * i; p <= N; p += i) {
            check[p] = true;
        }
    }

    for (int i = M; i <= N; i++) {
        if (!check[i])
            cout << i << '\n';
    }

}