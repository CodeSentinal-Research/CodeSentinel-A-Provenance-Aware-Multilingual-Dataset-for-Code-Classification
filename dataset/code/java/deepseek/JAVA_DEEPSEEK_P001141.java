import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int S = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(subsetSum(nums, N, S) ? "YES" : "NO");
    }

    private static boolean subsetSum(int[] nums, int N, int S) {
        boolean[] dp = new boolean[S + 1];
        dp[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = S; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[S];
    }
}
