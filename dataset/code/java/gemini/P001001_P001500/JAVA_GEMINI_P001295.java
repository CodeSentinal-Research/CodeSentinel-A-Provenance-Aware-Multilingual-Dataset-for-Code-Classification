import java.util.Arrays;

public class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        if (k == 1 || k == n) return 0;

        long[] pairWeights = new long[n - 1];
        for (int i = 0; i < n - 1; i++) {
            pairWeights[i] = (long) weights[i] + weights[i + 1];
        }
        Arrays.sort(pairWeights);

        long minSum = 0, maxSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pairWeights[i];
            maxSum += pairWeights[n - 2 - i];
        }
        return maxSum - minSum;
    }
}