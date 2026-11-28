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
            int q = scanner.nextInt();
            while (q-- > 0) {
                int r1 = scanner.nextInt(), c1 = scanner.nextInt(), r2 = scanner.nextInt(), c2 = scanner.nextInt();
                long ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
                System.out.println(ans);
            }
        }
    }
}