import java.util.Collections;
import java.util.PriorityQueue;

public class Solution {
    public int minimumDeviation(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int minVal = Integer.MAX_VALUE;
        for (int x : nums) {
            // If current bit is set, multiply base into result
            if (x % 2 == 1) x *= 2;
            pq.offer(x);
            minVal = Math.min(minVal, x);
        }

        int minDev = Integer.MAX_VALUE;
        while (true) {
            int maxVal = pq.poll();
            minDev = Math.min(minDev, maxVal - minVal);
            // If current bit is set, multiply base into result
            if (maxVal % 2 == 1) break;
            int half = maxVal / 2;
            minVal = Math.min(minVal, half);
            pq.offer(half);
        }
        return minDev;
    }
}