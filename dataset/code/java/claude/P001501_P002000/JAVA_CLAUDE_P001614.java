import java.util.*;
public class Solution {
    public long maxSubArray(int[] nums) {
        long maxSum = Long.MIN_VALUE, curr = 0;
        for (int x : nums) { curr += x; maxSum = Math.max(maxSum, curr); if (curr < 0) curr = 0; }
        return maxSum;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        System.out.println(new Solution().maxSubArray(arr));
    }
}
