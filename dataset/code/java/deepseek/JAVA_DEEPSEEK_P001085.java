import java.util.*;

public class Main {
    static class Edge {
        int to;
        int cost;
        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    static int N, M, S, T;
    static List<Edge>[] graph;
    static int[] dist;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        S = sc.nextInt();
        T = sc.nextInt();

        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        dist = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            graph[u].add(new Edge(v, w));
        }

        System.out.println(dfs(S, T));
    }

    static int dfs(int u, int v) {
        if (u == v) {
            return 1;
        }
        visited[u] = true;
        int res = 0;
        for (Edge e : graph[u]) {
            if (!visited[e.to]) {
                res += dfs(e.to, v);
            }
        }
        visited[u] = false;
        return res;
    }
}
