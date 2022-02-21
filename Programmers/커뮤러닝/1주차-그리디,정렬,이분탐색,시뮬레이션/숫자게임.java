// 시뮬레이션(구현) : 특정 상황을 재현하여 문제를 해결하는 방법

import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Integer[] aArray = Arrays.stream(A).boxed().toArray(Integer[]::new);
        Integer[] bArray = Arrays.stream(B).boxed().toArray(Integer[]::new);
        
        Arrays.sort(aArray, Collections.reverseOrder());
        Arrays.sort(bArray, Collections.reverseOrder());
        
        int idxB = 0;
        for (int idxA = 0; idxA < aArray.length; ++idxA) {
            if (aArray[idxA] < bArray[idxB]) {
                answer++;
                idxB++;
            }
        }
        
        return answer;
    }
}