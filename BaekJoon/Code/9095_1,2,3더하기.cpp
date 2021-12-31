#include <iostream>
#include <vector>

using namespace std;
vector<int> v(11);  // n은 11보다 작다
int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int T;  cin >> T;
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;

    for (int i = 4; i < 11; i++)
        v[i] = v[i-3] + v[i-2] + v[i-1];

    while (T--) {
        int n;  cin >> n;
        cout << v[n] << '\n';
    }
    return 0;
}