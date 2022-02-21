/*  Tip. 효율성 높이기
    1. Loop 개선
    2. 적절한 데이터 구조 사용
    3. 불필요한 객체 제거(Primitive Type 지양)  */
    
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