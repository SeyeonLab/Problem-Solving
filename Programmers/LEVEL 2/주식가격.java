import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer[]> stack = new Stack<>();
        
        for (int i = 0; i < prices.length; ++i) {
            Integer[] temp = {prices[i], i};
            
            if (stack.empty()) {
                stack.push(temp);
                continue;
            } else {
                while (stack.peek()[0] > prices[i]) {
                    answer[stack.peek()[1]] = i - stack.peek()[1];
                    stack.pop();
                    
                    if (stack.empty())
                        break;
                }
            }
            
            stack.push(temp);
        }
        
        while (!stack.empty()) {
            answer[stack.peek()[1]] = (prices.length-1) - stack.peek()[1];    
            stack.pop();
        }
        
        return answer;
    }
}

/*
import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
        for (int i = 0; i < prices.length; ++i) {
            int count = 0;a
            for (int j = i + 1; j < prices.length; ++j) {
                count++;
                
                if (prices[i] > prices[j])
                    break;
            }
            answer[i] = count;
        }
        return answer;
    }
}
*/