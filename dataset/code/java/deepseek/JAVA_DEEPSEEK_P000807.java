import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        System.out.println(countSubstrings(s));
    }

    private static long countSubstrings(String s) {
        long count = 0;
        int n = s.length();
        int[][] dp = new int[n][5];
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                for (int j = 0; j < 5; j++) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            if (s.charAt(i) == 'a') {
                dp[i][0]++;
            } else if (s.charAt(i) == 'e') {
                dp[i][1] = dp[i][0] + 1;
            } else if (s.charAt(i) == 'i') {
                dp[i][2] = dp[i][1] + 1;
            } else if (s.charAt(i) == 'o') {
                dp[i][3] = dp[i][2] + 1;
            } else if (s.charAt(i) == 'u') {
                dp[i][4] = dp[i][3] + 1;
            }
            count += dp[i][4];
        }
        return count;
    }
}
