import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        String[] nm = br.readLine().split(" ");
        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);
        int Q = Integer.parseInt(nm[2]);

        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            String[] edge = br.readLine().split(" ");
            int u = Integer.parseInt(edge[0]) - 1;
            int v = Integer.parseInt(edge[1]) - 1;
            graph.get(u).add(v);
        }

        for (int i = 0; i < Q; i++) {
            String[] query = br.readLine().split(" ");
            int u = Integer.parseInt(query[0]) - 1;
            int v = Integer.parseInt(query[1]) - 1;
            out.println(bfs(u, v, graph));
        }

        out.flush();
    }

    static String bfs(int start, int end, ArrayList<ArrayList<Integer>> graph) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[graph.size()];
        queue.add(start);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            if (node == end) {
                return "YES";
            }
            for (int neighbour : graph.get(node)) {
                if (!visited[neighbour]) {
                    queue.add(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return "NO";
    }
}
