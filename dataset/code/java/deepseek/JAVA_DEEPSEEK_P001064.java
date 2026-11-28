import java.util.*;

public class Main {
    static class Edge {
        int u, v;

        public Edge(int u, int v) {
            this.u = u;
            this.v = v;
        }
    }

    static boolean[][] graph;
    static int N, M, Q;
    static int[][] queries;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        Q = sc.nextInt();

        graph = new boolean[N][N];
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            graph[u][v] = graph[v][u] = true;
        }

        queries = new int[Q][2];
        for (int i = 0; i < Q; i++) {
            queries[i][0] = sc.nextInt() - 1;
            queries[i][1] = sc.nextInt() - 1;
        }

        for (int i = 0; i < Q; i++) {
            System.out.println(exists(queries[i][0], queries[i][1]) ? "YES" : "NO");
        }
    }

    static boolean exists(int u, int v) {
        return graph[u][v];
    }
}
