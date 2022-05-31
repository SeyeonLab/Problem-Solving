import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for (int command = 0; command < commands.length; command++) {
            int i = commands[command][0];
            int j = commands[command][1];
            int k = commands[command][2];

            int[] newArray = Arrays.copyOfRange(array, i-1, j);
            Arrays.sort(newArray);
            answer[command] = newArray[k-1];
        }
        
        return answer;
    }
}