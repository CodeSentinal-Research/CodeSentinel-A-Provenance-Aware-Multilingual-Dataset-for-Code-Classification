import java.util.*;

public class Main {
    static int N, M;
    static ArrayList<Integer>[] graph;
    static int[] depth;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        graph = new ArrayList[N + 1];
        depth = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u].add(v);
        }

        int motherVertex = -1;
        for (int i = 1; i <= N; i++) {
            if (depth[i] == 0 && dfs(i, -1)) {
                motherVertex = i;
                break;
            }
        }

        if (motherVertex == -1) {
            System.out.println(-1);
        } else {
            System.out.println(motherVertex);
        }
    }

    static boolean dfs(int node, int parent) {
        visited[node] = true;
        depth[node] = depth[parent] + 1;

        for (int neighbor : graph[node]) {
            if (depth[neighbor] == 0) {
                if (dfs(neighbor, node)) {
                    return true;
                }
            } else if (depth[neighbor] == depth[node] - 1 && visited[neighbor]) {
                return true;
            }
        }

        return false;
    }
}
