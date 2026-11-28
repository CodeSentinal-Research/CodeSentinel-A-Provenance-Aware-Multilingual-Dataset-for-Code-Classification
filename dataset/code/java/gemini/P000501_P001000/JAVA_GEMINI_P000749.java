import java.util.*;
public class Solution {
    static void varJumpPaths(int n, int m, int r, int c, String path) {
        if (r == n && c == m) {
            System.out.println(path);
            return;
        }
        for (int k = 1; k <= m - c; k++) {
            varJumpPaths(n, m, r, c + k, path + "H" + k);
        }
        for (int k = 1; k <= n - r; k++) {
            varJumpPaths(n, m, r + k, c, path + "V" + k);
        }
        for (int k = 1; k <= Math.min(n - r, m - c); k++) {
            varJumpPaths(n, m, r + k, c + k, path + "D" + k);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            varJumpPaths(scanner.nextInt(), scanner.nextInt(), 1, 1, "");
        }
    }
}