#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  cin.tie(NULL);

    int N;  cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);

    int M;  cin >> M;
    for (int i = 0; i < M; i++) {
        int key;  cin >> key;
        if (binary_search(A, A + N, key)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

}