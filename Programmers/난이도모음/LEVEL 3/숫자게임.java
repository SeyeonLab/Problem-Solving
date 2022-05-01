import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Integer[] aArray = Arrays.stream(A).boxed().toArray(Integer[]::new);
        Integer[] bArray = Arrays.stream(B).boxed().toArray(Integer[]::new);
        
        Arrays.sort(aArray, Collections.reverseOrder());
        Arrays.sort(bArray, Collections.reverseOrder());
        
        int idxA = 0, idxB = 0;
        while (idxA < aArray.length) {
            if (aArray[idxA] < bArray[idxB]) {
                answer++;
                idxB++;
            }
            idxA++;
        }
        
        return answer;
    }
}