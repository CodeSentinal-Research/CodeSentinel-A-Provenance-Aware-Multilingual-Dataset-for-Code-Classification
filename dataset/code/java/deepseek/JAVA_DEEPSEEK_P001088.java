import java.util.*;
import java.io.*;

public class Main {
    static int N, M, S, K;
    static ArrayList<ArrayList<Integer>> graph;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        graph = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        visited = new boolean[N];
        int result = dfs(S, K);
        System.out.println(result);
    }

    static int dfs(int node, int k) {
        if (visited[node]) {
            return 0;
        }
        visited[node] = true;
        if (k == 0) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < graph.get(node).size(); i++) {
            count += dfs(graph.get(node).get(i), k - 1);
        }
        return count;
    }
}
