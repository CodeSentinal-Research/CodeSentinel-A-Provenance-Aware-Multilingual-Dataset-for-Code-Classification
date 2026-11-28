import java.util.Scanner;

public class Solution {
    public static long matrixTrace(int[][] mat) {
        long trace = 0;
        for (int i = 0; i < mat.length; i++) {
            trace += mat[i][i];
        }
        return trace;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[][] mat = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) mat[i][j] = sc.nextInt();
            }
            System.out.println(matrixTrace(mat));
        }
        sc.close();
    }
}