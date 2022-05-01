import java.util.HashMap;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;

        HashMap<String, Integer> hm = new HashMap<>();

        for (String[] c : clothes) {
            String type = c[1];
            hm.put(type, hm.getOrDefault(type, 0) + 1);
        }

        for (String type : hm.keySet()) {
            answer *= hm.get(type) + 1;
        }

        return answer - 1;
    }
}