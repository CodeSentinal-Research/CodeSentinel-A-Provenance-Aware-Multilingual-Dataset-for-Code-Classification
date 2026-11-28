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
    static int N, S;
    static ArrayList<Edge>[] graph;
    static int[] dist;
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[u].add(new Edge(u, v, w));
        }
        dist = new int[N + 1];
        Arrays.fill(dist, -1);
        dist[S] = 0;
        visited = new boolean[N + 1];
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(S, S, 0));
        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            if (visited[e.v]) continue;
            visited[e.v] = true;
            for (Edge f : graph[e.v]) {
                if (dist[f.u] == -1 || dist[f.u] + f.w < dist[f.v]) {
                    dist[f.v] = dist[f.u] + f.w;
                    pq.add(new Edge(f.u, f.v, dist[f.v]));
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (dist[i] == -1) System.out.println(-1);
            else System.out.println(dist[i]);
        }
    }
}
