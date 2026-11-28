import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            PriorityQueue<Long> pq = new PriorityQueue<>();
            for (int i = 0; i < n; i++) pq.offer(sc.nextLong());

            long totalCost = 0;
            while (pq.size() > 1) {
                long f1 = pq.poll();
                long f2 = pq.poll();
                long cost = f1 + f2;
                totalCost += cost;
                pq.offer(cost);
            }
            System.out.println(totalCost);
        }
        sc.close();
    }
}