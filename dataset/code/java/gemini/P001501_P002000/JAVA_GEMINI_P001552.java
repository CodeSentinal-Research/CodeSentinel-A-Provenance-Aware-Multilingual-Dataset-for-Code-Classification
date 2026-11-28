import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), x = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int l = 0, minLen = Integer.MAX_VALUE;
            long curSum = 0;

            for (int r = 0; r < n; r++) {
                curSum += nums[r];
                while (curSum > x) {
                    minLen = Math.min(minLen, r - l + 1);
                    curSum -= nums[l++];
                }
            }
            System.out.println(minLen != Integer.MAX_VALUE ? minLen : 0);
        }
        sc.close();
    }
}