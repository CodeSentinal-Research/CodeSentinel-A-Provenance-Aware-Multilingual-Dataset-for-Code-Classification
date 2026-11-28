import java.util.*;

public class Main {
    static int N, E, M;
    static int[][] graph;
    static int[] color;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        E = sc.nextInt();
        M = sc.nextInt();

        graph = new int[E][3];
        color = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 0; i < E; i++) {
            graph[i][0] = sc.nextInt();
            graph[i][1] = sc.nextInt();
            graph[i][2] = sc.nextInt();
        }

        if (isPossible()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean isPossible() {
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0) {
                if (!dfs(i, 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean dfs(int node, int c) {
        if (c > M) {
            return false;
        }
        if (color[node] == 0) {
            color[node] = c;
        }
        visited[node] = true;

        for (int i = 0; i < E; i++) {
            if (graph[i][0] == node && !visited[graph[i][1]]) {
                if (!dfs(graph[i][1], c)) {
                    return false;
                }
            }
        }
        return true;
    }
}
