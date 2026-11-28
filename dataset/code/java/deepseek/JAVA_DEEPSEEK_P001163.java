import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String A = scanner.nextLine();
        String B = scanner.nextLine();
        String C = scanner.nextLine();

        System.out.println(canInterleave(A, B, C) ? "YES" : "NO");
    }

    private static boolean canInterleave(String A, String B, String C) {
        int lenA = A.length();
        int lenB = B.length();
        int lenC = C.length();

        if (lenA + lenB != lenC) {
            return false;
        }

        boolean[] dp = new boolean[lenB + 1];

        for (int i = 0; i <= lenA; i++) {
            for (int j = 0; j <= lenB; j++) {
                dp[j + 1] = dp[j + 1] && (i == 0 || dp[j]);
                if (i > 0 && A.charAt(i - 1) == C.charAt(i + j - 1)) {
                    dp[j + 1] = dp[j + 1] || (j == 0 || dp[j - 1]);
                }
            }
        }

        return dp[lenB];
    }
}
