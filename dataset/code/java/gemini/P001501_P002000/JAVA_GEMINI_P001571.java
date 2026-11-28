import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int maxDiff = 0;
            for (int i = 0; i <= n - k; i++) {
                maxDiff = Math.max(maxDiff, Math.abs(nums[i + k - 1] - nums[i]));
            }
            System.out.println(maxDiff);
        }
        sc.close();
    }
}