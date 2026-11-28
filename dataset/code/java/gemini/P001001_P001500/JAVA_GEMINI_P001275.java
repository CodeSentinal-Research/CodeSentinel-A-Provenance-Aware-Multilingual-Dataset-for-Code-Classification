import java.util.*;

public class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][] workers = new double[n][2];
        for (int i = 0; i < n; i++) {
            workers[i][0] = (double) wage[i] / quality[i];
            workers[i][1] = quality[i];
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));

        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        double qualSum = 0, minCost = Double.MAX_VALUE;

        for (double[] w : workers) {
            double ratio = w[0], q = w[1];
            pq.offer(q);
            qualSum += q;
            if (pq.size() > k) {
                qualSum -= pq.poll();
            }
            if (pq.size() == k) {
                minCost = Math.min(minCost, qualSum * ratio);
            }
        }
        return minCost;
    }
}