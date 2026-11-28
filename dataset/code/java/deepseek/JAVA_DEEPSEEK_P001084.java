import java.util.*;

public class Main {
    static int N;
    static int[][] graph;
    static boolean[] visited;
    static int[] path;
    static int start;

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

        start = scanner.nextInt();

        if (hamiltonianCycle(1, start)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean hamiltonianCycle(int current, int start) {
        visited[start] = true;
        path[current] = start;

        if (current == N) {
            if (graph[start][0] == 1) {
                return true;
            } else {
                return false;
            }
        } else {
            for (int i = 1; i < N; i++) {
                if (graph[start][i] == 1 && !visited[i]) {
                    if (hamiltonianCycle(current + 1, i)) {
                        return true;
                    }
                }
            }
        }

        visited[start] = false;
        return false;
    }
}
