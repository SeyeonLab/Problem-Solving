/*  Tip. 좋은 프로그램을 만드는 방법
    1. 당면한 문제를 해결한다
    2. 좋은코드가 되도록 계속 리팩토링한다
    3. 람다식을 활용할 수 있는 Stream을 응용한다  */

import java.util.stream.*;

class Solution { 
    public int solution(int[] budgets, int M) {
        int answer = 0;
        int min = 0;
        int max = IntStream.of(budgets).max().orElse(0);
        // int max = 0;

        // for (int b : budgets) max = Math.max(max, budgets[i]);

        while (min <= max) {
            final int mid = (min + max) / 2;
            // final int mid = min + (max - min) / 2;
            
            int sum = IntStream.of(budgets).map(b -> Math.min(b, mid)).sum();
            
            /* int sum = 0;

            for (int b : budgets) {
                if (b > mid) sum += mid;
                else sum += b;
            } */
            
            if (sum <= M) {
                min = mid + 1;
                answer = Math.max(answer, mid);
            } else {
                max = mid - 1;
            }
        }
        
        return answer;
    }
}