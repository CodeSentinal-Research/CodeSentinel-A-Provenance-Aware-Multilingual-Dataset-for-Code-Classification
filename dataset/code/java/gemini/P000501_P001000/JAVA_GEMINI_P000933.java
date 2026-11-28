import java.util.Scanner;

public class Solution {
    public static boolean isIdentity(int[][] mat) {
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int exp = (i == j) ? 1 : 0;
                if (mat[i][j] != exp) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[][] mat = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) mat[i][j] = sc.nextInt();
            }
            System.out.println(isIdentity(mat) ? "YES" : "NO");
        }
        sc.close();
    }
}