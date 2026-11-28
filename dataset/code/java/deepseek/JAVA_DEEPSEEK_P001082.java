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

        for (int i = 1; i <= N; i++) {
            if (graph[i].size() > 0 && dfs(i, -1)) {
                System.out.println("YES");
                printPath(i, -1);
                return;
            }
        }

        System.out.println("NO");
    }

    static boolean dfs(int v, int parent) {
        visited[v] = true;

        for (int u : graph[v]) {
            if (!visited[u]) {
                if (dfs(u, v)) {
                    System.out.println("YES");
                    printPath(u, v);
                    return true;
                }
            } else if (u != parent) {
                System.out.println("YES");
                printPath(u, v);
                return true;
            }
        }

        return false;
    }

    static void printPath(int v, int u) {
        System.out.print(v + " ");
        if (v == u) {
            System.out.println(u);
        } else {
            printPath(u, v);
        }
    }
}
