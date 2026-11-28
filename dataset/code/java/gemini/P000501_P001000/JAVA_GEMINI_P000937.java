import java.util.Scanner;

public class Solution {
    private static final long MOD = 1000000007L;

    private static long[][] matMul(long[][] a, long[][] b) {
        int n = a.length;
        long[][] res = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    public static long[][] matPow(long[][] mat, long p) {
        int n = mat.length;
        long[][] res = new long[n][n];
        for (int i = 0; i < n; i++) res[i][i] = 1;
        long[][] base = mat;
        while (p > 0) {
            // If current bit is set, multiply base into result
            if (p % 2 == 1) res = matMul(res, base);
            base = matMul(base, base);
            p /= 2;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long p = sc.nextLong();
            long[][] mat = new long[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) mat[i][j] = sc.nextLong();
            }
            long[][] ans = matPow(mat, p);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(ans[i][j] + (j == n - 1 ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}