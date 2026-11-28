import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt(), k = sc.nextInt();
            int[][] mat = new int[m][n];
            int[][] p = new int[m + 1][n + 1];

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = sc.nextInt();
                    p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
                }
            }

            int maxSide = 0;
            for (int side = 1; side <= Math.min(m, n); side++) {
                for (int i = 0; i <= m - side; i++) {
                    for (int j = 0; j <= n - side; j++) {
                        int sum = p[i + side][j + side] - p[i][j + side] - p[i + side][j] + p[i][j];
                        if (sum <= k) maxSide = Math.max(maxSide, side);
                    }
                }
            }
            System.out.println(maxSide);
        }
        sc.close();
    }
}