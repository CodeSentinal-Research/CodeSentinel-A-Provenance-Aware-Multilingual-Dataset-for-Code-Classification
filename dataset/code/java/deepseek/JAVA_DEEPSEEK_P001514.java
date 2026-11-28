import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(longestSemiRepetitiveSubstring(input));
    }

    public static int longestSemiRepetitiveSubstring(String s) {
        int n = s.length();
        int[][] dp = new int[n + 1][2];
        dp[0][0] = dp[0][1] = 0;
        int maxLen = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            if (s.charAt(i - 1) == s.charAt(i - 2) && s.charAt(i - 1) == '0') {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][0];
            } else if (s.charAt(i - 1) == s.charAt(i - 2)) {
                dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0]);
            } else {
                dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + 1);
            }
            maxLen = Math.max(maxLen, Math.max(dp[i][0], dp[i][1]));
        }
        return maxLen;
    }
}
