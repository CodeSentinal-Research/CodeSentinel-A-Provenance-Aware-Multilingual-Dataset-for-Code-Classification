import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.next();
        String B = sc.next();
        int m = A.length();
        int n = B.length();
        
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A.charAt(i - 1) == B.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + A.charAt(i - 1);
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int lcsSum = 0;
        // Reconstruct LCS sum? No, problem asks for ASCII delete sum.
        // Sum of ASCII of A + Sum of ASCII of B - 2 * Sum of ASCII of LCS
        
        int sumA = 0, sumB = 0;
        for (char c : A.toCharArray()) sumA += c;
        for (char c : B.toCharArray()) sumB += c;
        
        // Need LCS ASCII sum
        int[][] asciiDp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A.charAt(i - 1) == B.charAt(j - 1)) {
                    asciiDp[i][j] = asciiDp[i - 1][j - 1] + A.charAt(i - 1);
                } else {
                    asciiDp[i][j] = Math.max(asciiDp[i - 1][j], asciiDp[i][j - 1]);
                }
            }
        }
        System.out.println(sumA + sumB - 2 * asciiDp[m][n]);
    }
}
