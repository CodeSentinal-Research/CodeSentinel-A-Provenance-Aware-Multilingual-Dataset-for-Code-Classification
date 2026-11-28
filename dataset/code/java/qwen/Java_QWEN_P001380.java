import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        int[] freq = new int[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((a, b) -> {
            if(b.getValue() != a.getValue()) return b.getValue() - a.getValue();
            return a.getKey() - b.getKey();
        });
        
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) pq.offer(new AbstractMap.SimpleEntry<>((char)(i+'a'), freq[i]));
        }
        
        StringBuilder sb = new StringBuilder();
        while(!pq.isEmpty()) {
            Map.Entry<Character, Integer> entry = pq.poll();
            for(int i=0; i<entry.getValue(); i++) sb.append(entry.getKey());
        }
        System.out.println(sb.toString());
    }
}
