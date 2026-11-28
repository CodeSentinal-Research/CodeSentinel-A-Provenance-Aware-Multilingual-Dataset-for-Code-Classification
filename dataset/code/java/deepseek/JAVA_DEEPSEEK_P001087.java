import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        boolean[] visited = new boolean[N + 1];
        boolean[][] graph = new boolean[N + 1][N + 1];

        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph[u][v] = graph[v][u] = true;
        }

        if (isTree(graph, visited, 1, -1)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean isTree(boolean[][] graph, boolean[] visited, int node, int parent) {
        visited[node] = true;
        for (int i = 1; i <= graph.length - 1; i++) {
            if (graph[node][i]) {
                if (visited[i]) {
                    if (i != parent) {
                        return false;
                    }
                } else if (!visited[i]) {
                    if (!isTree(graph, visited, i, node)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
