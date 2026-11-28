import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        System.out.println(longestDuplicateSubstring(s));
    }

    public static String longestDuplicateSubstring(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        int maxLen = 0;
        int endingIndex = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if (dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        endingIndex = i;
                    }
                }
            }
        }

        if (maxLen == 0) {
            return "";
        }

        return s.substring(endingIndex, endingIndex + maxLen);
    }
}
