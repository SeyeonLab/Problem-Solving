import java.util.*;

class Solution {

    class P {
        int open;   // 열린괄호
        int close;  // 닫힌괄호

        P(int open, int close) {
            this.open = open;
            this.close = close;
        }
    }

    public int solution(int n) {
        int answer = 0;

        Stack<P> stack = new Stack<>();
        stack.push(new P(0, 0));

        while (!stack.isEmpty()) {
            P p = stack.pop();
            
            if (p.open > n) continue;               
            if (p.open < p.close) continue;         // 열린 괄호보다 닫힌 괄호의 개수가 많을 경우
            if (p.open + p.close == n*2) {
                answer++;
                continue;
            }

            stack.push(new P(p.open + 1, p.close));
            stack.push(new P(p.open, p.close + 1));
        }

        return answer;
    }
}