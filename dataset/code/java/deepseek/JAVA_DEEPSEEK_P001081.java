import java.util.*;

public class Main {
    static int N, M;
    static ArrayList<Integer>[] graph;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        graph = new ArrayList[N + 1];
        visited = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u].add(v);
            graph[v].add(u);
        }
        if (isEulerian()) {
            System.out.println("YES");
            List<Integer> circuit = new ArrayList<>();
            dfs(1, 0, circuit);
            for (int v : circuit) {
                System.out.print(v + " ");
            }
        } else {
            System.out.println("NO");
        }
    }

    static boolean isEulerian() {
        int odd = 0;
        for (int u = 1; u <= N; u++) {
            if (graph[u].size() > 0) {
                odd++;
            }
        }
        return odd == 0 || odd == 2;
    }

    static void dfs(int v, int p, List<Integer> circuit) {
        visited[v] = true;
        circuit.add(v);
        for (int u : graph[v]) {
            if (u != p) {
                dfs(u, v, circuit);
            }
        }
    }
}
