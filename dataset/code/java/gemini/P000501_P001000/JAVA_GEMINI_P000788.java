import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int k = scanner.nextInt();
            long cur = 0;
            for (int i = 0; i < k; i++) cur += nums[i];
            long maxSum = cur;
            for (int i = k; i < n; i++) {
                cur += nums[i] - nums[i - k];
                maxSum = Math.max(maxSum, cur);
            }
            System.out.printf(Locale.US, "%.5f\n", (double)maxSum / k);
        }
    }
}