import java.util.PriorityQueue;

public class Solution {
    public int maximumProduct(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int n : nums) pq.offer(n);

        for (int i = 0; i < k; i++) {
            pq.offer(pq.poll() + 1);
        }

        long res = 1, MOD = 1000000007;
        while (!pq.isEmpty()) {
            res = (res * pq.poll()) % MOD;
        }
        return (int)res;
    }
}