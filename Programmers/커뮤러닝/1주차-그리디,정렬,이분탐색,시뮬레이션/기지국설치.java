class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int idx = 0;
        int location = 1;

        while (location <= n) {
            if (idx < stations.length && location >= stations[idx]-w) {
                location = stations[idx] + w + 1;
                idx++;
                continue;
            }
            
            location += w * 2 + 1;
            answer++;
        }

        return answer;
    }
}