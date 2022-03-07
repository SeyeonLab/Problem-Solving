class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int size = triangle.length;
        int[][] DP = new int[size + 1][size + 1];
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i == 0) {
                    DP[i][j] = triangle[i][j];
                    break;
                }
                
                if (j == 0) DP[i][j] = DP[i-1][j] + triangle[i][j];
                else DP[i][j] = Math.max(DP[i-1][j-1], DP[i-1][j]) + triangle[i][j];
            }
        }    
        for (int i = 0; i < size; ++i)
            answer = Math.max(answer, DP[size - 1][i]);
            
        return answer;
    }
}