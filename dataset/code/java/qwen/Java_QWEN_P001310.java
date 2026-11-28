import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] sticks = new int[n];
        for(int i=0; i<n; i++) sticks[i] = sc.nextInt();
        
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(int s : sticks) pq.offer((long)s);
        
        long cost = 0;
        while(pq.size() > 1) {
            long a = pq.poll();
            long b = pq.poll();
            long sum = a + b;
            cost += sum;
            pq.offer(sum);
        }
        System.out.println(cost);
    }
}
