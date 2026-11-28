import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] freq = new int[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) pq.offer(new int[]{i, freq[i]});
        }
        
        StringBuilder sb = new StringBuilder();
        int[] prev = {-1, 0};
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            sb.append((char)(curr[0] + 'a'));
            curr[1]--;
            if(prev[1] > 0) pq.offer(prev);
            prev = curr;
        }
        
        if(sb.length() != s.length()) System.out.println("IMPOSSIBLE");
        else System.out.println(sb.toString());
    }
}
