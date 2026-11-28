import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String A = scanner.nextLine();
        String B = scanner.nextLine();

        System.out.println(minDeleteSum(A, B));
    }

    public static int minDeleteSum(String A, String B) {
        int m = A.length();
        int n = B.length();

        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i * 'a';
        }

        for (int j = 0; j <= n; j++) {
            dp[0][j] = j * 'b';
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A.charAt(i - 1) == B.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j] + A.charAt(i - 1), dp[i][j - 1] + B.charAt(j - 1));
                }
            }
        }

        return dp[m][n];
    }
}
