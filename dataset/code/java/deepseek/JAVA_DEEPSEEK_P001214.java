import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(minTurns(input));
    }

    public static int minTurns(String s) {
        int[][] dp = new int[s.length()][s.length()];
        for (int gap = 0; gap < s.length(); gap++) {
            for (int i = 0, j = gap; j < s.length(); i++, j++) {
                if (gap == 0) {
                    dp[i][j] = 0;
                } else if (gap == 1) {
                    dp[i][j] = s.charAt(i) == s.charAt(j) ? 0 : 1;
                } else {
                    dp[i][j] = s.charAt(i) == s.charAt(j) ? dp[i + 1][j - 1] : dp[i][j - 1] + 1;
                }
            }
        }
        return dp[0][s.length() - 1];
    }
}
