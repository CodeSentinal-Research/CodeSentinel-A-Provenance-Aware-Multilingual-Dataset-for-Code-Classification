import java.util.*;

public class Main {
    private static final int UNVISITED = -1;
    private static final int INFINITE = Integer.MAX_VALUE;

    private static class Edge implements Comparable<Edge> {
        int u, v, w;

        Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Edge other) {
            return w - other.w;
        }
    }

    private static int[] parent;
    private static List<Edge>[] graph;
    private static int[] depth;
    private static boolean[] visited;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine();

        parent = new int[N];
        graph = new List[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            String[] line = scanner.nextLine().split(" ");
            int u = Integer.parseInt(line[0]) - 1;
            int v = Integer.parseInt(line[1]) - 1;
            int w = Integer.parseInt(line[2]);
            graph[u].add(new Edge(u, v, w));
            graph[v].add(new Edge(v, u, w));
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            visited = new boolean[N];
            depth = new int[N];
            dfs(i, INFINITE, result);
            if (depth[i] != INFINITE) {
                result.add(i);
            }
        }

        if (result.isEmpty()) {
            System.out.println("NONE");
        } else {
            Collections.sort(result, Comparator.naturalOrder());
            for (int i : result) {
                System.out.println(i + 1);
            }
        }
    }

    private static void dfs(int u, int parent, List<Integer> result) {
        visited[u] = true;
        depth[u] = depth[parent] + 1;

        for (Edge edge : graph[u]) {
            if (edge.u == parent) {
                continue;
            }
            if (visited[edge.v]) {
                continue;
            }

            dfs(edge.v, u, result);
            depth[u] = Math.min(depth[u], depth[edge.v]);
        }
    }
}
