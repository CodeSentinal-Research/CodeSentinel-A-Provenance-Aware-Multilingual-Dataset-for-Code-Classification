import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), m = scanner.nextInt();
            long[][] pref = new long[n + 1][m + 1];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    long val = scanner.nextLong();
                    pref[i + 1][j + 1] = val + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
                }
            }
            int k = scanner.nextInt();
            for (int i = 0; i < n; i++) {
                int r1 = Math.max(0, i - k), r2 = Math.min(n - 1, i + k);
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < m; j++) {
                    int c1 = Math.max(0, j - k), c2 = Math.min(m - 1, j + k);
                    long ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
                    sb.append(ans).append(j == m - 1 ? "" : " ");
                }
                System.out.println(sb.toString());
            }
        }
    }
}