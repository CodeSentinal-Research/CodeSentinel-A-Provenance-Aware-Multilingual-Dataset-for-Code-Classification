import java.util.*;

public class Solution {
    public static int maxDistinctElements(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : arr) map.put(x, map.getOrDefault(x, 0) + 1);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int count : map.values()) {
            if (count > 1) pq.offer(count - 1);
        }

        while (!pq.isEmpty() && k > 0) {
            int c = pq.poll();
            if (k >= c) {
                k -= c;
            } else {
                c -= k;
                k = 0;
                pq.offer(c);
            }
        }

        int distinct = map.size();
        if (k > 0) distinct -= k;
        return Math.max(0, distinct);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(maxDistinctElements(arr, k));
        }
        sc.close();
    }
}