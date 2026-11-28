import java.util.*;

public class Main {
    static long maxProduct = 0;
    static long total = 0;
    static long[] values;
    static List<Integer>[] graph;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        values = new long[n+1];
        for (int i = 1; i <= n; i++) {
            values[i] = sc.nextLong();
            total += values[i];
        }
        graph = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u].add(v);
            graph[v].add(u);
        }
        dfs(1, -1);
        System.out.println(maxProduct);
    }

    static long dfs(int u, int parent) {
        long subTree = values[u];
        for (int v : graph[u]) {
            if (v != parent) {
                subTree += dfs(v, u);
            }
        }
        if (u != 1) {
            maxProduct = Math.max(maxProduct, subTree * (total - subTree));
       }
        return subTree;
    }
}
