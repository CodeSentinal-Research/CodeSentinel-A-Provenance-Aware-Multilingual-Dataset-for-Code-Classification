import java.util.*;

public class Solution {
    private static boolean isSafe(int u, int c, List<List<Integer>> adj, int[] color) {
        for (int v : adj.get(u)) {
            if (color[v] == c) return false;
        }
        return true;
    }

    private static boolean solve(int u, int n, int m, List<List<Integer>> adj, int[] color) {
        if (u == n) return true;
        for (int c = 1; c <= m; c++) {
            if (isSafe(u, c, adj, color)) {
                color[u] = c;
                if (solve(u + 1, n, m, adj, color)) return true;
                color[u] = 0;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), numEdges = sc.nextInt(), m = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < numEdges; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            int[] color = new int[n];
            System.out.println(solve(0, n, m, adj, color) ? "YES" : "NO");
        }
        sc.close();
    }
}