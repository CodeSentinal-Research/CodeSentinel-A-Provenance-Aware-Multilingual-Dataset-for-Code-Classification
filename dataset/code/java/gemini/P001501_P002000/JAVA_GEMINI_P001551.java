import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int l = 0, maxLen = 0;
            long curSum = 0;

            for (int r = 0; r < n; r++) {
                curSum += nums[r];
                while (curSum > k && l <= r) {
                    curSum -= nums[l++];
                }
                if (curSum <= k) {
                    maxLen = Math.max(maxLen, r - l + 1);
                }
            }
            System.out.println(maxLen);
        }
        sc.close();
    }
}