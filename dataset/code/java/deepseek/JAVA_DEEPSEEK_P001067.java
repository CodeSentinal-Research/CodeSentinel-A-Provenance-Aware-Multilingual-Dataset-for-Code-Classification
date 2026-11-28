import java.util.*;
import java.io.*;

public class Main {
    static int N, M, S;
    static ArrayList<ArrayList<Integer>> graph;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        graph = new ArrayList<>();
        visited = new boolean[N + 1];

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
        }

        int reachable = dfs(S);
        System.out.println(reachable);
    }

    static int dfs(int node) {
        visited[node] = true;
        int count = 1;
        for (int neighbour : graph.get(node)) {
            if (!visited[neighbour]) {
                count += dfs(neighbour);
            }
        }
        return count;
    }
}
