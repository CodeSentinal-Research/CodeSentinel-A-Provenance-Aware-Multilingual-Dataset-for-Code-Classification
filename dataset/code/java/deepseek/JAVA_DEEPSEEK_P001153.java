import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(countPalindromicSubstrings(s));
    }

    public static long countPalindromicSubstrings(String s) {
        int n = s.length();
        long[][] dp = new long[n][n];
        boolean[][] pal = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
            dp[i][i] = 1;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                pal[i][i + 1] = true;
                dp[i][i + 1] = 2;
            }
        }

        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                if (s.charAt(i) == s.charAt(j) && pal[i + 1][j - 1]) {
                    pal[i][j] = true;
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1 - dp[i + 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
            }
        }

        long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sum += dp[i][j];
            }
        }

        return sum;
    }
}
