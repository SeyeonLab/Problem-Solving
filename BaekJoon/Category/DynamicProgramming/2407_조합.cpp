#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
const int MAX = 100 + 1;
string DP[MAX][MAX];

void Input() {
	ios::sync_with_stdio(false);  cin.tie(NULL);
    cin >> N >> M;
}

string bigNumAdd(string num1, string num2) {
    long long sum = 0;
    string answer;

    while (!num1.empty() || !num2.empty() || sum) {
        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        
        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }

        answer.push_back((sum % 10) + '0');
        sum /= 10;
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}

string Combination(int n, int r) {
    if (r == 0 || n == r) {
        return "1";
    }

    string &answer = DP[n][r];
    if (answer != "")
        return answer;
    
    answer = bigNumAdd(Combination(n - 1, r - 1), Combination(n - 1, r));
    return answer;
}

void Solve() {
    Input();
    cout << Combination(N, M) << '\n';
}

int main(void) {

	Solve();
	return 0;
}    
