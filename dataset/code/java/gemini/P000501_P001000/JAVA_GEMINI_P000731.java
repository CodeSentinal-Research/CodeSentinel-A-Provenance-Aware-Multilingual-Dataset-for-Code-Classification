import java.util.*;
public class Solution {
    static int totalCount = 0;
    static void backtrack(int n, int r, boolean[] cols, boolean[] d1, boolean[] d2) {
        if (r == n) { totalCount++; return; }
        for (int c = 0; c < n; c++) {
            if (cols[c] || d1[r + c] || d2[r - c + n]) continue;
            cols[c] = d1[r + c] = d2[r - c + n] = true;
            backtrack(n, r + 1, cols, d1, d2);
            cols[c] = d1[r + c] = d2[r - c + n] = false;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            backtrack(n, 0, new boolean[n], new boolean[2 * n], new boolean[2 * n]);
            System.out.println(totalCount);
        }
    }
}