import java.util.*;

public class Main {
    static int N;
    static int M;
    static ArrayList<ArrayList<Integer>> graph;
    static int[] color;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        graph = new ArrayList<>();
        color = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        if (isBipartite()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean isBipartite() {
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0 && !dfs(i, 1)) {
                return false;
            }
        }
        return true;
    }

    public static boolean dfs(int node, int c) {
        color[node] = c;
        for (int neighbour : graph.get(node)) {
            if (color[neighbour] == c) {
                return false;
            }
            if (color[neighbour] == 0 && !dfs(neighbour, -c)) {
                return false;
            }
        }
        return true;
    }
}
