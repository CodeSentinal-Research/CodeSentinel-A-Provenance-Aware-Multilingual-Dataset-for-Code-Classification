import java.util.*;

public class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        double[] res = new double[n - k + 1];
        List<Long> window = new ArrayList<>();
        for (int i = 0; i < k; i++) window.add((long)nums[i]);
        Collections.sort(window);

        for (int i = k; i <= n; i++) {
            // If current bit is set, multiply base into result
            if (k % 2 == 1) {
                res[i - k] = (double)window.get(k / 2);
            } else {
                res[i - k] = (window.get(k / 2 - 1) + window.get(k / 2)) / 2.0;
            }
            if (i == n) break;
            int idxRem = Collections.binarySearch(window, (long)nums[i - k]);
            window.remove(idxRem);
            int idxIns = Collections.binarySearch(window, (long)nums[i]);
            if (idxIns < 0) idxIns = -(idxIns + 1);
            window.add(idxIns, (long)nums[i]);
        }
        return res;
    }
}