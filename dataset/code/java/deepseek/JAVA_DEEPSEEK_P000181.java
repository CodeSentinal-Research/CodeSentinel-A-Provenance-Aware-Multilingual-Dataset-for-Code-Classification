import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        int M = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(maxSumTwoNonOverlapping(nums, L, M));
    }

    private static int maxSumTwoNonOverlapping(int[] nums, int L, int M) {
        int n = nums.length;
        int[] sums = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        int[] dp1 = new int[n + 1];
        int[] dp2 = new int[n + 1];
        int maxL = 0;
        for (int i = L; i <= n; i++) {
            maxL = Math.max(maxL, sums[i] - sums[i - L]);
            dp1[i] = Math.max(dp1[i - 1], maxL);
        }

        int maxM = 0;
        for (int i = M; i <= n; i++) {
            maxM = Math.max(maxM, sums[i] - sums[i - M]);
            dp2[i] = Math.max(dp2[i - 1], maxM);
        }

        int res = 0;
        for (int i = L; i <= n; i++) {
            res = Math.max(res, dp1[i] + dp2[n] - sums[i]);
        }
        return res;
    }
}
