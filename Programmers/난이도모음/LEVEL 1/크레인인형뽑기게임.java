import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> bucket = new Stack<>();
        
        for (int move : moves) {
            for (int i = 0; i < board.length; i++) {
                if (board[i][move-1] == 0) continue;
                else {
                    int doll = board[i][move-1];
                    if (!bucket.empty() && bucket.peek() == doll) {
                        answer += 2;
                        bucket.pop();
                    }
                    else {
                        bucket.push(doll);
                    }
                    board[i][move-1] = 0;
                    break;
                }
            }
        }
        return answer;
    }
}