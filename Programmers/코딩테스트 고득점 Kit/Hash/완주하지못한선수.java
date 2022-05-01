import java.util.Set;
import java.util.HashMap;
import java.util.Iterator;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();

        for (String member : participant)
            hm.put(member, hm.getOrDefault(member, 0) + 1);
        for (String member : completion)
            hm.put(member, hm.get(member) - 1);
        Set<String> keys = hm.keySet();
        Iterator<String> it = keys.iterator();

        while (it.hasNext()) {
            String key = it.next();
            int count = hm.get(key);

            if (count > 0)
                answer += key;
        }

        return answer;
    }
}