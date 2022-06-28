import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int sc : scoville) {
            pq.add(sc);
        }
        
        while (pq.size() > 1 && pq.peek() < K) {
            int first = pq.poll();
            int second = pq.poll();
            
            pq.add(first + (second * 2));
            answer++;
        }
        
        if (pq.peek() < K)
            return -1;
        else
            return answer;
    }
}