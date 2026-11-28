import java.util.*;

public class Main {
    static int N;
    static int[][] graph;
    static boolean[] visited;
    static int[] path;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        int M = scanner.nextInt();
        graph = new int[N][N];
        visited = new boolean[N];
        path = new int[N];

        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        if (hamiltonianPath(0)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean hamiltonianPath(int current) {
        if (current == N) {
            return graph[path[current - 1]][path[0]] == 1;
        }

        for (int i = 1; i < N; i++) {
            if (!visited[i] && (graph[path[current - 1]][i] == 1 || graph[path[current - 1]][path[current]] == 1)) {
                visited[i] = true;
                path[current] = i;

                if (hamiltonianPath(current + 1)) {
                    return true;
                }

                visited[i] = false;
            }
        }

        return false;
    }
}
