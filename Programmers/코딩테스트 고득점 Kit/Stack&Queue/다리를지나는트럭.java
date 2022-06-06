import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer> queue = new LinkedList<>();
        int answer = 0;
        int now_weight = 0;
        
        while (queue.size() < bridge_length) queue.add(0);      
        
        for (int idx = 0; idx < truck_weights.length;) {
            if (queue.size() == bridge_length) {
                now_weight -= queue.poll();
            }
            
            if (now_weight + truck_weights[idx] > weight) {
                queue.add(0);
            }
            else {
                queue.add(truck_weights[idx]);
                now_weight += truck_weights[idx];
                idx++;
            }    
            answer++;
        }
        
        while (queue.size() > 0) {
            queue.remove();
            answer++;
        }
        
        return answer;
    }
}