import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLine()) {
            String s = sc.nextLine().trim();
            int n = s.length();
            int m = (n + 1) / 2;
            char[] symbols = new char[m];
            char[] operators = new char[m - 1];
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) symbols[i / 2] = s.charAt(i);
                else operators[i / 2] = s.charAt(i);
            }

            long MOD = 1003;
            long[][] T = new long[m][m];
            long[][] F = new long[m][m];

            for (int i = 0; i < m; i++) {
                T[i][i] = symbols[i] == 'T' ? 1 : 0;
                F[i][i] = symbols[i] == 'F' ? 1 : 0;
            }

            for (int len = 2; len <= m; len++) {
                for (int i = 0; i <= m - len; i++) {
                    int j = i + len - 1;
                    for (int k = i; k < j; k++) {
                        char op = operators[k];
                        long totalIK = (T[i][k] + F[i][k]) % MOD;
                        long totalKJ = (T[k + 1][j] + F[k + 1][j]) % MOD;

                        if (op == '&') {
                            T[i][j] = (T[i][j] + T[i][k] * T[k + 1][j]) % MOD;
                            F[i][j] = (F[i][j] + totalIK * totalKJ - T[i][k] * T[k + 1][j]) % MOD;
                        } else if (op == '|') {
                            F[i][j] = (F[i][j] + F[i][k] * F[k + 1][j]) % MOD;
                            T[i][j] = (T[i][j] + totalIK * totalKJ - F[i][k] * F[k + 1][j]) % MOD;
                        } else if (op == '^') {
                            T[i][j] = (T[i][j] + T[i][k] * F[k + 1][j] + F[i][k] * T[k + 1][j]) % MOD;
                            F[i][j] = (F[i][j] + T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j]) % MOD;
                        }
                    }
                }
            }
            System.out.println((T[0][m - 1] % MOD + MOD) % MOD);
        }
        sc.close();
    }
}