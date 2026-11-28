import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), target = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            boolean[] dp = new boolean[target + 1];
            // Update dynamic programming state transition
            dp[0] = true;
            for (int x : arr) {
                for (int j = target; j >= x; j--) {
                    // Update dynamic programming state transition
                    dp[j] = dp[j] || dp[j - x];
                }
            }
            System.out.println(dp[target] ? "YES" : "NO");
        }
        sc.close();
    }
}