import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt();
            int[][] mat = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) mat[i][j] = sc.nextInt();
            }

            long ans = 0;
            for (int l = 0; l < n; l++) {
                int[] rowDiff = new int[m];
                for (int r = l; r < n; r++) {
                    for (int i = 0; i < m; i++) rowDiff[i] += (mat[i][r] == 1 ? 1 : -1);

                    Map<Integer, Integer> count = new HashMap<>();
                    count.put(0, 1);
                    int cur = 0;
                    for (int i = 0; i < m; i++) {
                        cur += rowDiff[i];
                        ans += count.getOrDefault(cur, 0);
                        count.put(cur, count.getOrDefault(cur, 0) + 1);
                    }
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}