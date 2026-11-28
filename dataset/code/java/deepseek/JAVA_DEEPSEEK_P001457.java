import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s1 = scanner.nextLine();
        String s2 = scanner.nextLine();

        int length1 = s1.length();
        int length2 = s2.length();

        int[][] dp = new int[length1 + 1][length2 + 1];
        int maxLen = 0;

        for (int i = 1; i <= length1; i++) {
            for (int j = 1; j <= length2; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen = Math.max(maxLen, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        System.out.println(maxLen);
    }
}
