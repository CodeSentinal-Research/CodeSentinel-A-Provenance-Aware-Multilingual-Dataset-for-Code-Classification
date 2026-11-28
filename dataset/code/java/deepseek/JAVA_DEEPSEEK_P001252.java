import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; i++) {
            pairs[i] = new int[]{scanner.nextInt(), scanner.nextInt()};
        }
        scanner.close();
        System.out.println(maxChainLength(pairs));
    }

    private static int maxChainLength(int[][] pairs) {
        int n = pairs.length;
        if (n == 0) return 0;
        if (n == 1) return 1;
        int[] dp = new int[n];
        int[] end = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            int maxEnd = 0;
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    maxEnd = Math.max(maxEnd, dp[j]);
                }
            }
            dp[i] = maxEnd + 1;
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
