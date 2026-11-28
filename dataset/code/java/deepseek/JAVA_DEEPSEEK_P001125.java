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
    static int N, M, S;
    static ArrayList<Edge>[] graph;
    static int[] dist;
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
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
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[S] = 0;
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(S, 0, 0));
        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            if (visited[e.v]) continue;
            visited[e.v] = true;
            for (Edge ne : graph[e.v]) {
                if (dist[ne.v] > dist[e.v] + ne.w) {
                    dist[ne.v] = dist[e.v] + ne.w;
                    pq.add(new Edge(ne.v, dist[ne.v], ne.w));
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (dist[i] == Integer.MAX_VALUE) System.out.println(-1);
            else System.out.println(dist[i]);
        }
    }
}
