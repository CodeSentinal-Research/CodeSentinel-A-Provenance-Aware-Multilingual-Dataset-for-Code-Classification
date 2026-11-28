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
            long threshold = scanner.nextLong();
            int maxLen = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    while (i + maxLen < n && j + maxLen < m) {
                        long sum = pref[i + maxLen + 1][j + maxLen + 1] - pref[i][j + maxLen + 1] - pref[i + maxLen + 1][j] + pref[i][j];
                        if (sum <= threshold) maxLen++;
                        else break;
                    }
                }
            }
            System.out.println(maxLen);
        }
    }
}