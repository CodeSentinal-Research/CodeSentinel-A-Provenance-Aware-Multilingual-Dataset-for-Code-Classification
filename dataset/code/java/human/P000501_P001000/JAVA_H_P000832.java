// package removed

/**
 * LeetCode 410: Split Array Largest Sum
 * Given an array nums which consists of non-negative integers and an integer m,
 * you can split the array into m non-empty continuous subarrays.
 * Write an algorithm to minimize the largest sum among these m subarrays.
 */
public class SplitArrayLargestSum {

    public int splitArray(int[] nums, int m) {
        if (nums == null || nums.length == 0 || m <= 0) {
            return 0;
        }
        
        int n = nums.length;
        long[][] dp = new long[n + 1][m + 1];
        
        // Initialize with large values
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = Long.MAX_VALUE;
            }
        }
        dp[0][0] = 0;
        
        long[] prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    long sum = prefixSum[i] - prefixSum[k];
                    dp[i][j] = Math.min(dp[i][j], Math.max(dp[k][j - 1], sum));
                }
            }
        }
        
        return (int) dp[n][m];
    }

    public static void main(String[] args) {
        SplitArrayLargestSum solution = new SplitArrayLargestSum();
        
        // Test cases
        System.out.println("Min largest sum for [7,2,5,10,8], m=2: " + 
            solution.splitArray(new int[]{7, 2, 5, 10, 8}, 2)); // 18
        System.out.println("Min largest sum for [1,2,3,4,5], m=2: " + 
            solution.splitArray(new int[]{1, 2, 3, 4, 5}, 2)); // 9
    }
}
