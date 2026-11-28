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
    static int N, M, K;
    static int[] dist;
    static ArrayList<Edge>[] graph;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0;
        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[u].add(new Edge(u, v, w));
            graph[v].add(new Edge(v, u, w));
        }
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int source = Integer.parseInt(st.nextToken());
            dijkstra(source);
            for (int j = 1; j <= N; j++) out.println(dist[j] == Integer.MAX_VALUE ? -1 : dist[j]);
        }
        out.close();
    }
    static void dijkstra(int source) {
        boolean[] visited = new boolean[N + 1];
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(source, source, 0));
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            if (visited[edge.v]) continue;
            visited[edge.v] = true;
            dist[edge.v] = Math.min(dist[edge.v], edge.w);
            for (Edge e : graph[edge.v]) {
                if (!visited[e.v]) pq.add(e);
            }
        }
    }
}
