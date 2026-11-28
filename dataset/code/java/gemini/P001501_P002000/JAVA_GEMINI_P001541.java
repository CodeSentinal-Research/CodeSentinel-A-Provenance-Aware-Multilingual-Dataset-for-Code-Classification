import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            long curSum = 0;
            for (int i = 0; i < k; i++) curSum += nums[i];
            long maxSum = curSum;

            for (int i = k; i < n; i++) {
                curSum += nums[i] - nums[i - k];
                maxSum = Math.max(maxSum, curSum);
            }
            System.out.println(maxSum);
        }
        sc.close();
    }
}