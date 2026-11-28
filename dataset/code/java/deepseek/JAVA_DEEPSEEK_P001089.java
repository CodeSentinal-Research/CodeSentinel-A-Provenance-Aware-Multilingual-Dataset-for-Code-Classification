import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[] parent;
    static ArrayList<ArrayList<Integer>> adj;
    static int[] size;
    static int[] center;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        N = Integer.parseInt(br.readLine());
        parent = new int[N + 1];
        adj = new ArrayList<>();
        size = new int[N + 1];
        center = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 1; i <= N; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 1; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        dfs(1, -1);

        for (int i = 1; i <= N; i++) {
            if (center[i] == 0) {
                center[i] = i;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (center[i] != 0) {
                System.out.println(center[i]);
            }
        }
    }

    static void dfs(int node, int par) {
        visited[node] = true;
        size[node] = 1;
        for (int child : adj.get(node)) {
            if (child == par) {
                continue;
            }
            if (!visited[child]) {
                dfs(child, node);
                size[node] += size[child];
                if (size[child] > size[center[node]]) {
                    center[node] = child;
                }
            }
        }
    }
}
