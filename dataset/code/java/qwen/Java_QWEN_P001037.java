import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] tasks = new String(sc.nextLine()).toCharArray(); // Fix input reading
        int k = sc.nextInt();
        
        int[] freq = new int[26];
        for(char c : tasks) freq[c-'A']++;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int f : freq) if(f > 0) pq.offer(f);
        
        int time = 0;
        while(!pq.isEmpty()) {
            List<Integer> temp = new ArrayList<>();
            for(int i=0; i<k+1; i++) {
                if(!pq.isEmpty()) {
                    temp.add(pq.poll());
                }
            }
            for(int f : temp) {
                if(f > 1) pq.offer(f-1);
            }
            time += pq.isEmpty() ? temp.size() : k+1;
        }
        System.out.println(time);
    }
}
