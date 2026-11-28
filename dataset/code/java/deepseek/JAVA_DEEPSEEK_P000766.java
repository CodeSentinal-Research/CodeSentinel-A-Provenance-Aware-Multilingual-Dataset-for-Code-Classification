import java.util.Scanner;

public class Main {
    static int dp[][][];
    static String s;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        dp = new int[s.length()][s.length()][2];
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        System.out.println(solve(0, s.length() - 1, 1));
    }

    static int solve(int i, int j, int isTrue) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            if (isTrue == 1) {
                return s.charAt(i) == 'T' ? 1 : 0;
            } else {
                return s.charAt(i) == 'F' ? 1 : 0;
            }
        }
        if (dp[i][j][isTrue] != -1) {
            return dp[i][j][isTrue];
        }
        int ans = 0;
        for (int k = i + 1; k <= j; k += 2) {
            int lt = solve(i, k - 1, 1);
            int lf = solve(i, k - 1, 0);
            int rt = solve(k + 1, j, 1);
            int rf = solve(k + 1, j, 0);
            if (s.charAt(k) == '&') {
                if (isTrue == 1) {
                    ans += lt * rt;
                } else {
                    ans += lf * rf + lf * rt + lt * rf;
                }
            } else if (s.charAt(k) == '|') {
                if (isTrue == 1) {
                    ans += lt * rt + lf * rt + lt * rf;
                } else {
                    ans += lf * rf;
                }
            } else if (s.charAt(k) == '^') {
                if (isTrue == 1) {
                    ans += lt * rf + lf * rt;
                } else {
                    ans += lt * rt + lf * rf;
                }
            }
        }
        return dp[i][j][isTrue] = ans % 1003;
    }
}
