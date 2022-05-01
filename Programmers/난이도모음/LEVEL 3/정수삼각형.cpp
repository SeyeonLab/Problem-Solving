#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));    
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0) {
                dp[i][j] = triangle[i][j];
                break;
            }
            
            if (j == 0) {
                dp[i][j] = triangle[i][j] + dp[i-1][j]; 
            }
            else {
                dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    
    for (int i = 0; i < size; i++) {
        answer = max(answer, dp[size - 1][i]);
    }
    return answer;
}