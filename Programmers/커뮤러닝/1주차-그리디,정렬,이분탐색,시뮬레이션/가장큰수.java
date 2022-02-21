/*  Tip. Java API 활용
    1. Java 언어를 사용한다 == Java가 제공하는 라이브러리를 사용
    2. 기본 라이브러리인 java.lang.*, java.util.*의 사용법을 숙지  */

import java.util.*;

class Solution {
    public String solution(int[] numbers) {

        // Java 8의 람다식을 활용한 풀이
        String answer = IntStream.of(numbers).mapToObj(String::valueOf).sorted((s1,s2) -> (s2+s1).compareTo(s1+s2)).collect(Collectors.joining());
        
        /*
        String answer = "";
        String[] arr = new String[numbers.length];
        
        for (int i = 0; i < numbers.length; ++i)
            arr[i] = String.valueOf(numbers[i]);

        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                return (b+a).compareTo(a+b);
            }
        });
        
        for (String str : arr)
            answer += str;
        */

        if (arr[0].charAt(0) == '0') return "0";

        return answer;
    }
}