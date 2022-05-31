import java.util.*;

class Solution {
    public int solution(int[] citations) {
        // 1. 정렬
        Arrays.sort(citations);

        // 2. H-index 찾기
        for (int i = 0; i < citations.length; ++i) {
            int h = citations.length - i;   // 2-(1). h편 이상 인용
            if (citations[i] >= h)          // 2-(2). h번 이상 인용된 논문인가?
                return h;
        }
        return 0;
    }
}