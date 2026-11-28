import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        int[] freq = new int[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if(b[1] != a[1]) return b[1] - a[1];
            return a[0] - b[0];
        });
        
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) pq.offer(new int[]{i, freq[i]});
        }
        
        StringBuilder sb = new StringBuilder();
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            for(int i=0; i<curr[1]; i++) sb.append((char)(curr[0] + 'a'));
        }
        System.out.println(sb.toString());
    }
}
