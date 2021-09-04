#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 5000 + 1;
const int MOD = 1000000;
long long num[MAX];
long long DP[MAX];
string s;

void Input() {
	ios::sync_with_stdio(false);  cin.tie(NULL);
    cin >> s;
    
    for (int i = 1; i <= s.length(); i++) {
        num[i] = s[i - 1] - '0';
    }
}

void Solution() {
    if (s.length() == 1 && s[0] == '0') {
        cout << 0 << '\n';
        return;
    }

    DP[0] = 1;
    for (int i = 1; i <= s.size(); i++) 
    {
        if (num[i] >= 1 && num[i] <= 9) 
        {
            DP[i] = (DP[i - 1] + DP[i]) % MOD;
        }

        if (i == 1) continue;

        int tmp = num[i] + num[i - 1] * 10;
        if (tmp >= 10 && tmp <= 26)
        {
            DP[i] = (DP[i - 2] + DP[i]) % MOD;
        }
    }

    cout << DP[s.size()] << '\n';
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
	Solve();
	return 0;
}    
