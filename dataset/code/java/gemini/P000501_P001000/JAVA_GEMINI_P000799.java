import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), m = scanner.nextInt();
            long[][] pref = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    pref[i][j] = scanner.nextLong();
                    if (i > 0) pref[i][j] += pref[i - 1][j];
                    if (j > 0) pref[i][j] += pref[i][j - 1];
                    if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
                }
            }
            for (int i = 0; i < n; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < m; j++) sb.append(pref[i][j]).append(j == m - 1 ? "" : " ");
                System.out.println(sb.toString());
            }
        }
    }
}