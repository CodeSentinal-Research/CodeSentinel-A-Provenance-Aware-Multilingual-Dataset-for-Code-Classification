import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
    public static long minCostRopes(long[] arr) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (long x : arr) pq.offer(x);
        long totalCost = 0;
        while (pq.size() > 1) {
            long a = pq.poll();
            long b = pq.poll();
            long cost = a + b;
            totalCost += cost;
            pq.offer(cost);
        }
        return totalCost;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextLong();
            System.out.println(minCostRopes(arr));
        }
        sc.close();
    }
}