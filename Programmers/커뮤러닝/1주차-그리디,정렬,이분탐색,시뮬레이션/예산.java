class Solution { 
    public int solution(int[] budgets, int M) {
        long answer = 0;
        long sum = 0, low = 1, high = 0;
        
        for (int i = 0; i < budgets.length; ++i) {
            sum += budgets[i];
            high = Math.max(high, budgets[i]);
        }
        
        if (sum <= M) {
            answer = high;
            return (int)answer;
        }
        
        while (low <= high) {
            long mid = low + (high - low) / 2;
            
            sum = 0;
            for (int budget : budgets) {
                if (budget >= mid) sum += mid;
                else sum += budget;
            }
            
            if (sum <= M) {
                answer = Math.max(answer, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return (int)answer;
    }
}