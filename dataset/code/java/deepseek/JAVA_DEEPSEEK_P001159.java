import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(decodeWays(input));
    }

    public static int decodeWays(String s) {
        int[] dp = new int[s.length() + 2];
        dp[0] = 1;
        dp[1] = 0;

        for (int i = 2; i < dp.length; i++) {
            dp[i] = 0;
        }

        for (int i = 2; i < dp.length; i++) {
            int oneDigit = s.charAt(i - 2) - '0';
            int twoDigits = (s.charAt(i - 1) - '0') * 10 + (s.charAt(i) - '0');

            if (oneDigit >= 1) {
                dp[i] += dp[i - 1];
            }

            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[dp.length - 1];
    }
}
