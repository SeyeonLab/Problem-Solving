import java.util.Stack;
import java.util.ArrayList;
import java.util.stream.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> answer = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        int release = 0;
        
        for (int i = 0; i < progresses.length; ++i) {
            int count = 0;
            
            // 기능 구현 100% 까지 걸리는 날짜 계산
            while (progresses[i] < 100) {
                progresses[i] += speeds[i];
                count++;
            }
            
            if (stack.empty()) {
                stack.push(count);
                release++;
            } else {
                // 뒤에 있는 기능이 앞의 기능보다 빠르게 완성되면 배포 개수 + 1
                if (stack.peek() >= count) release++;
                // 뒤에 있는 기능이 앞의 기능보다 느리게 완성되면 지금까지의 기능을 배포
                else {
                    stack.pop();
                    stack.push(count);
                    answer.add(release);
                    release = 1;
                }
            }
        }
        answer.add(release);
        return answer.stream().mapToInt(i -> i).toArray(); // ArrayList를 int[]로 변환
    }
}