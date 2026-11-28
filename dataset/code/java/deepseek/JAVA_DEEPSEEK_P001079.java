import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        String[] nm = br.readLine().split(" ");
        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);
        List<Integer>[] graph = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            String[] edge = br.readLine().split(" ");
            int u = Integer.parseInt(edge[0]);
            int v = Integer.parseInt(edge[1]);
            graph[u].add(v);
            graph[v].add(u);
        }
        List<Integer>[] components = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            components[i] = new ArrayList<>();
        }
        for (int i = 1; i <= N; i++) {
            if (components[i].isEmpty()) {
                dfs(i, i, graph, components);
            }
        }
        List<Integer> bridges = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            if (components[i].size() == 1) {
                bridges.add(i);
            }
        }
        if (bridges.isEmpty()) {
            out.println("NONE");
        } else {
            for (int bridge : bridges) {
                out.println(bridge);
            }
        }
        out.close();
    }

    static void dfs(int node, int parent, List<Integer>[] graph, List<Integer>[] components) {
        components[node].add(parent);
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                if (components[neighbor].isEmpty()) {
                    dfs(neighbor, node, graph, components);
                }
                components[node].add(neighbor);
            }
        }
    }
}
