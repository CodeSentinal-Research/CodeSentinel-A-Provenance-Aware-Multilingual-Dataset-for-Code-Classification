import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(findSlices(nums));
    }

    private static long findSlices(int[] nums) {
        int n = nums.length;
        long[] dp = new long[n];
        long[] cnt = new long[n];
        cnt[0] = 1;
        long res = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] - nums[j] == nums[i - 1] - nums[j] && i - j >= 2) {
                    dp[i] += cnt[j] * (i - j);
                }
            }
            cnt[i] = dp[i] + cnt[i - 1];
            res += cnt[i];
        }
        return res;
    }
}
