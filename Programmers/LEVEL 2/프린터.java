import java.util.Queue;
import java.util.PriorityQueue;
import java.util.LinkedList;
import java.util.Collections;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < priorities.length; ++i) {
            pq.add(priorities[i]);
            q.add(i);
        }
        
        while (true) {
            if (pq.isEmpty())
                break;
            
            int index = q.peek();
            int pick = priorities[index];
            q.poll();
            
            if (pick == pq.peek()) {
                pq.poll();
                answer++;
                
                if (location == index)
                    break;
            }
            else {
                q.add(index);
            }
            
        }
        
        return answer;
    }
}