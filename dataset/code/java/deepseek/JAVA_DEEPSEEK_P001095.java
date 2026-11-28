import java.util.Scanner;

public class Main {
    private static final int INF = Integer.MAX_VALUE / 2;
    private static int[][] graph;
    private static int[][] cap;
    private static int[] parent;

    private static int ford(int s, int t) {
        int res = 0;
        for (int u = t; u != s; u = parent[u]) {
            int v = parent[u];
            res += Math.min(cap[u][v], graph[u][v]);
        }
        return res;
    }

    private static boolean dfs(int u, int t) {
        if (u == t) {
            return true;
        }
        for (int v = 0; v < graph[u].length; v++) {
            if (graph[u][v] > 0 && dfs(v, t)) {
                parent[v] = u;
                return true;
            }
        }
        return false;
    }

    private static int maxFlow(int s, int t) {
        int res = 0;
        int f;
        while (true) {
            f = ford(s, t);
            if (f == 0) {
                break;
            }
            res += f;
            for (int u = t; u != s; u = parent[u]) {
                int v = parent[u];
                graph[u][v] -= f;
                graph[v][u] += f;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int S = scanner.nextInt();
        int T = scanner.nextInt();

        graph = new int[N][N];
        cap = new int[N][N];
        parent = new int[N];

        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int capacity = scanner.nextInt();
            graph[u][v] = capacity;
            cap[u][v] = capacity;
        }

        int maxFlow = maxFlow(S, T);
        System.out.println(maxFlow);
    }
}
