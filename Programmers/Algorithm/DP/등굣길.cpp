#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<long long>> v(n+1, vector<long long>(m+1, 0));
    int answer = 0;
    
    v[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;            
            v[i][j] = (v[i-1][j] + v[i][j-1]) % 1000000007;
            for (int k = 0; k < puddles.size(); k++) {
                if (puddles[k][1] == i && puddles[k][0] == j) {
                    v[i][j] = 0;
                    break;
                }
            }
        }
    }
    answer = v[n][m] % 1000000007;
    return answer;
}