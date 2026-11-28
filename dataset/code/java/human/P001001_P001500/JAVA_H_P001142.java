package programs.dp;

/**
 * LeetCode 416: Partition Equal Subset Sum
 * Given a non-empty array nums containing only positive integers, find if the array can be partitioned
 * into two subsets such that the sum of elements in both subsets is equal.
 */
public class PartitionEqualSubsetSum {

    public boolean canPartition(int[] nums) {
        if (nums == null || nums.length == 0) {
            return false;
        }
        
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        if (sum % 2 != 0) {
            return false;
        }
        
        int target = sum / 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;
        
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[target];
    }

    public static void main(String[] args) {
        PartitionEqualSubsetSum solution = new PartitionEqualSubsetSum();
        
        // Test cases
        System.out.println("Can partition [1,5,11,5]: " + 
            solution.canPartition(new int[]{1, 5, 11, 5})); // true
        System.out.println("Can partition [1,2,3,5]: " + 
            solution.canPartition(new int[]{1, 2, 3, 5})); // false
    }
}
