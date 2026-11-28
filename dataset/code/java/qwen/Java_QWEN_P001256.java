import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] freq = new int[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int f : freq) if(f > 0) pq.offer(f);
        
        int deletions = 0;
        while(!pq.isEmpty()) {
            int curr = pq.poll();
            if(!pq.isEmpty() && pq.peek() == curr) {
                deletions++;
                pq.offer(curr - 1);
            }
        }
        System.out.println(deletions);
    }
}
