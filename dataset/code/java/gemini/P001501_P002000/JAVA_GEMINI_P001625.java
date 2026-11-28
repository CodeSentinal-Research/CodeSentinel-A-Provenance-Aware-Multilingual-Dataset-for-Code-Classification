import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt();
            long[][] p = new long[m][n];

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    p[i][j] = sc.nextLong();
                    if (i > 0) p[i][j] += p[i - 1][j];
                    if (j > 0) p[i][j] += p[i][j - 1];
                    if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];
                    System.out.print(p[i][j] + (j == n - 1 ? "" : " "));
                }
                System.out.println();
            }
        }
        sc.close();
    }
}