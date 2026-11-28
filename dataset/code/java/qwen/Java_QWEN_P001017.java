import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] ropes = new long[n];
        for(int i=0; i<n; i++) ropes[i] = sc.nextLong();
        
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(long r : ropes) pq.offer(r);
        
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
