#include <iostream>
#include <string>

using namespace std;

const int MOD = 1234567891;
const int MUL = 31;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

    long long sum = 0, r = 1, M = 1234567891;
    int L; cin >> L;
    string s; cin >> s;

    for (int i = 0; i < s.length(); i++) {
        sum = (sum + (s[i] - 'a' + 1) * r) % MOD; 
        r = (r * MUL) % MOD;
    }

    cout << sum;

    return 0;
}