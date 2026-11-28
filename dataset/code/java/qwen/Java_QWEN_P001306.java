import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] sizes = new int[n];
        for(int i=0; i<n; i++) sizes[i] = sc.nextInt();
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int s : sizes) pq.offer(s);
        
        long cost = 0;
        while(pq.size() > 1) {
            int a = pq.poll();
            int b = pq.poll();
            int sum = a + b;
            cost += sum;
            pq.offer(sum);
        }
        System.out.println(cost);
    }
}
