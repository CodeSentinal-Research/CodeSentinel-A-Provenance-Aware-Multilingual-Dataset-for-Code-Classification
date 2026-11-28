import java.util.*;

public class Solution {
    public int maximumRobots(int[] chargeTimes, int[] runningCosts, long budget) {
        Deque<Integer> dq = new ArrayDeque<>();
        int l = 0;
        long sumCost = 0;

        for (int r = 0; r < chargeTimes.length; r++) {
            sumCost += runningCosts[r];
            while (!dq.isEmpty() && chargeTimes[dq.peekLast()] <= chargeTimes[r]) dq.pollLast();
            dq.offerLast(r);

            // Binary search loop to narrow down range
            while (l <= r && chargeTimes[dq.peekFirst()] + (r - l + 1) * sumCost > budget) {
                if (dq.peekFirst() == l) dq.pollFirst();
                sumCost -= runningCosts[l++];
            }
        }
        return chargeTimes.length - l;
    }
}