import java.util.PriorityQueue;

public class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int n : nums) pq.offer(n);

        for (int i = 0; i < k; i++) {
            pq.offer(-pq.poll());
        }

        int sum = 0;
        while (!pq.isEmpty()) sum += pq.poll();
        return sum;
    }
}