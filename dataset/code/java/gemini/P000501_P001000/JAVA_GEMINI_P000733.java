import java.util.*;
public class Solution {
    static boolean isSafe(int node, int c, List<List<Integer>> adj, int[] colors) {
        for (int neighbor : adj.get(node)) {
            if (colors[neighbor] == c) return false;
        }
        return true;
    }
    static boolean backtrack(int node, int v, int m, List<List<Integer>> adj, int[] colors) {
        if (node == v) return true;
        for (int c = 1; c <= m; c++) {
            if (isSafe(node, c, adj, colors)) {
                colors[node] = c;
                if (backtrack(node + 1, v, m, adj, colors)) return true;
                colors[node] = 0;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int v = scanner.nextInt(), e = scanner.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < v; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < e; i++) {
                int u = scanner.nextInt(), w = scanner.nextInt();
                adj.get(u).add(w); adj.get(w).add(u);
            }
            int m = scanner.nextInt();
            System.out.println(backtrack(0, v, m, adj, new int[v]) ? "true" : "false");
        }
    }
}