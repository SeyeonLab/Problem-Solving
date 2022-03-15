import java.util.HashMap;

class Solution {
    public boolean solution(String[] phone_book) {
        HashMap<String, Integer> map = new HashMap<>();
        
        for (String phone : phone_book)
            map.put(phone, phone.length());
        
        for (String phone : phone_book) {
            for (int index = 0; index < phone.length(); index++){
                String temp = phone.substring(0, index);
                System.out.println(temp);
                if (map.containsKey(temp))
                    return false;
            }
        }
        
        return true;
    }
}