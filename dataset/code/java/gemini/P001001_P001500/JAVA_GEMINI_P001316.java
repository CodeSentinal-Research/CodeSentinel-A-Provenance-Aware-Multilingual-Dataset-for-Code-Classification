import java.util.Scanner;

public class Solution {
    private static boolean isSafe(int node, int c, int v, int[][] adj, int[] color) {
        for (int i = 0; i < v; i++) {
            if (adj[node][i] == 1 && color[i] == c) return false;
        }
        return true;
    }

    private static boolean solve(int node, int m, int v, int[][] adj, int[] color) {
        if (node == v) return true;
        for (int c = 1; c <= m; c++) {
            if (isSafe(node, c, v, adj, color)) {
                color[node] = c;
                if (solve(node + 1, m, v, adj, color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int v = sc.nextInt(), m = sc.nextInt(), e = sc.nextInt();
            int[][] adj = new int[v][v];
            for (int i = 0; i < e; i++) {
                int u = sc.nextInt(), w = sc.nextInt();
                adj[u][w] = 1;
                adj[w][u] = 1;
            }
            int[] color = new int[v];
            System.out.println(solve(0, m, v, adj, color) ? 1 : 0);
        }
        sc.close();
    }
}