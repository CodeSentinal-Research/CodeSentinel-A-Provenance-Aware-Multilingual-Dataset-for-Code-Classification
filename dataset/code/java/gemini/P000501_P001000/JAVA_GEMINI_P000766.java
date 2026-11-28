import java.util.*;
public class Solution {
    static long[][][] memo;
    static long solve(String s, int i, int j, int isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue == 1) return s.charAt(i) == 'T' ? 1 : 0;
            else return s.charAt(i) == 'F' ? 1 : 0;
        }
        if (memo[i][j][isTrue] != -1) return memo[i][j][isTrue];
        long ans = 0;
        for (int k = i + 1; k < j; k += 2) {
            char op = s.charAt(k);
            long lt = solve(s, i, k - 1, 1), lf = solve(s, i, k - 1, 0);
            long rt = solve(s, k + 1, j, 1), rf = solve(s, k + 1, j, 0);
            if (op == '&') {
                if (isTrue == 1) ans += lt * rt;
                else ans += lt * rf + lf * rt + lf * rf;
            } else if (op == '|') {
                if (isTrue == 1) ans += lt * rt + lt * rf + lf * rt;
                else ans += lf * rf;
            } else if (op == '^') {
                if (isTrue == 1) ans += lt * rf + lf * rt;
                else ans += lt * rt + lf * rf;
            }
        }
        return memo[i][j][isTrue] = ans;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int n = s.length();
            memo = new long[n][n][2];
            for (long[][] row : memo) for (long[] cell : row) Arrays.fill(cell, -1);
            System.out.println(solve(s, 0, n - 1, 1));
        }
    }
}