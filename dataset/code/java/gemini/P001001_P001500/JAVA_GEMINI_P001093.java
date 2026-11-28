import java.util.Scanner;

public class Solution {
    private static boolean permute(int idx, int n, int[] p, boolean[] used, boolean[][] adj1, boolean[][] adj2) {
        if (idx == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj1[i][j] != adj2[p[i]][p[j]]) return false;
                }
            }
            return true;
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                p[idx] = i;
                if (permute(idx + 1, n, p, used, adj1, adj2)) return true;
                used[i] = false;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            boolean[][] adj1 = new boolean[n][n];
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj1[u][v] = adj1[v][u] = true;
            }
            boolean[][] adj2 = new boolean[n][n];
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj2[u][v] = adj2[v][u] = true;
            }
            int[] p = new int[n];
            boolean[] used = new boolean[n];
            System.out.println(permute(0, n, p, used, adj1, adj2) ? "YES" : "NO");
        }
        sc.close();
    }
}