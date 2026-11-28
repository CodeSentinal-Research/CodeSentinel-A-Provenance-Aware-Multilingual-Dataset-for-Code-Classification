package Greedy;

import java.util.*;

/**
 * ============================================================
 * PROBLEM: Maximum Performance of a Team
 * ============================================================
 *
 * You are given:
 *   - n engineers
 *   - speed[i]
 *   - efficiency[i]
 *
 * Choose at most k engineers such that:
 *
 *   performance = (sum of speeds) * (minimum efficiency)
 *
 * Return max performance % (1e9 + 7)
 *
 * ============================================================
 * DIRECT APPROACH (Infeasible)
 * ------------------------------------------------------------
 * Try all subsets of size ≤ k → exponential
 *
 * ============================================================
 * OPTIMIZED APPROACH (Greedy + Heap) 
 * ------------------------------------------------------------
 *
 * KEY INSIGHT:
 *   Fix the minimum efficiency first.
 *
 * Steps:
 *   1. Pair engineers: (efficiency, speed)
 *   2. Sort by efficiency DESC
 *   3. Iterate:
 *        - current efficiency = min efficiency
 *        - maximize sum of speeds
 *
 *   4. Use min-heap to keep top k speeds
 *
 * Time: O(N log N)
 * Space: O(N)
 *
 * ============================================================
 */

public class MaxPerformanceTeam {

    static class Engineer {
        int speed;
        int efficiency;

        Engineer(int speed, int efficiency) {
            this.speed = speed;
            this.efficiency = efficiency;
        }
    }

    public static int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        final int MOD = 1_000_000_007;

        // Step 1: Create engineer list
        Engineer[] engineers = new Engineer[n];
        for (int i = 0; i < n; i++) {
            engineers[i] = new Engineer(speed[i], efficiency[i]);
        }

        // Step 2: Sort by efficiency DESC
        Arrays.sort(engineers, (a, b) -> b.efficiency - a.efficiency);

        // Min heap to maintain top k speeds
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        long speedSum = 0;
        long maxPerformance = 0;

        for (Engineer eng : engineers) {
            // Add current speed
            minHeap.offer(eng.speed);
            speedSum += eng.speed;

            // If more than k engineers, remove smallest amongst the top speeds.
            if (minHeap.size() > k) {
                speedSum -= minHeap.poll();
            }

            // Calculate performance
            long performance = speedSum * eng.efficiency;

            maxPerformance = Math.max(maxPerformance, performance);
        }

        return (int) (maxPerformance % MOD);
    }

    /**
     * DRIVER MAIN
     */
    public static void main(String[] args) {

        int n = 6;
        int[] speed = {2, 10, 3, 1, 5, 8};
        int[] efficiency = {5, 4, 3, 9, 7, 2};
        int k = 2;

        int result = maxPerformance(n, speed, efficiency, k);

        System.out.println("Maximum Performance: " + result);
    }
}