import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        List<Integer>[] graph = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            int u = Integer.parseInt(input[0]);
            int v = Integer.parseInt(input[1]);
            graph[v].add(u);
        }

        List<Integer> safe = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            if (dfs(i, graph, safe)) {
                safe.add(i);
            }
        }

        Collections.sort(safe);
        for (int i : safe) {
            out.print(i + " ");
        }
        out.println();

        out.close();
    }

    static boolean dfs(int node, List<Integer>[] graph, List<Integer> safe) {
        if (safe.contains(node)) {
            return true;
        }

        if (graph[node].isEmpty()) {
            return false;
        }

        List<Integer> children = graph[node];
        for (int child : children) {
            if (!dfs(child, graph, safe)) {
                return false;
            }
        }

        safe.add(node);
        graph[node].clear();
        return true;
    }
}
