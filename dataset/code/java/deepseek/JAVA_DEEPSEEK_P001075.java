import java.util.*;
import java.io.*;

public class Main {
    static class Edge implements Comparable<Edge> {
        int u, v, w;
        Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
        public int compareTo(Edge other) {
            return w - other.w;
        }
    }
    static int[] dist;
    static boolean[] visited;
    static List<Edge>[] graph;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[S] = 0;
        visited = new boolean[N + 1];
        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[u].add(new Edge(u, v, w));
        }
        if (bellmanFord(N, M, S)) {
            for (int i = 1; i <= N; i++) {
                System.out.println(dist[i] == Integer.MAX_VALUE ? "INF" : dist[i]);
            }
        } else {
            System.out.println("NEGATIVE CYCLE");
        }
    }
    public static boolean bellmanFord(int N, int M, int S) {
        for (int i = 0; i < N; i++) {
            for (Edge e : graph[S]) {
                if (dist[e.u] != Integer.MAX_VALUE && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }
        for (Edge e : graph[S]) {
            if (dist[e.u] != Integer.MAX_VALUE && dist[e.u] + e.w < dist[e.v]) {
                return false;
            }
        }
        return true;
    }
}
