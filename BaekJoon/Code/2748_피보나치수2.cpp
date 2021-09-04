#include <iostream>

using namespace std;

const int MAX = 91;
int N;
long long fibonacci[MAX];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i <= N; i++) {
        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
    }
    cout << fibonacci[N] << '\n';

    return 0;
}