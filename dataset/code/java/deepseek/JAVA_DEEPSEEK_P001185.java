import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        int[] dp = new int[n + 2];
        int[] sum = new int[n + 2];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + sum[nums[i]] * nums[i];
            dp[i + 2] = Math.max(dp[i + 1], dp[i]);
            sum[nums[i]]++;
        }
        System.out.println(Math.max(dp[n], dp[n + 1]));
    }
}
