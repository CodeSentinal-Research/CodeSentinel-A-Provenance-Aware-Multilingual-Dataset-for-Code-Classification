import java.util.*;
public class Solution {
    static void diagonalPaths(int n, int m, int r, int c, String path) {
        if (r == n && c == m) {
            System.out.println(path);
            return;
        }
        if (r < n && c < m) diagonalPaths(n, m, r + 1, c + 1, path + "D");
        if (c < m) diagonalPaths(n, m, r, c + 1, path + "H");
        if (r < n) diagonalPaths(n, m, r + 1, c, path + "V");
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            diagonalPaths(scanner.nextInt(), scanner.nextInt(), 1, 1, "");
        }
    }
}