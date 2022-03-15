import java.util.*;

class Pair implements Comparable<Pair> {
    private int first;
    private int second;
    
    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
    
    public int getFirst() {
        return first;
    }
    
    public int getSecond() {
        return second;
    }
    
    @Override
    public int compareTo(Pair p) {
        if (this.first > p.first) return -1;
        else if (this.first < p.first) return 1;
        else {
            if (this.second > p.second) return 1;
            else if (this.second < p.second) return -1;
        }
        return 0;
    }
}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> genre = new HashMap<>();
        TreeMap<String, ArrayList<Pair>> play = new TreeMap<>();
        
        for (int i = 0; i < genres.length; ++i) {
            genre.put(genres[i], genre.getOrDefault(genres[i], 0) + plays[i]);
            Pair p = new Pair(plays[i], i);
            if (!play.containsKey(genres[i])) {
                play.put(genres[i], new ArrayList<Pair>());
                play.get(genres[i]).add(p);
            }
            else
                play.get(genres[i]).add(p);
        }
        
        List<String> keySet = new ArrayList<>(genre.keySet());
        keySet.sort((o1, o2) -> genre.get(o2) - genre.get(o1));
        
        int size = 0;
        for (String key : keySet) {
            if (play.get(key).size() < 2) size += 1;
            else size += 2;
        }
        
        int index = 0;
        int[] answer = new int[size];
        
        for (String key : keySet) {
            Collections.sort(play.get(key));
            if (play.get(key).size() < 2) {
                answer[index++] = play.get(key).get(0).getSecond();
            }
            else {
                answer[index++] = play.get(key).get(0).getSecond();
                answer[index++] = play.get(key).get(1).getSecond();
            }
        }
        
        return answer;
    }
}