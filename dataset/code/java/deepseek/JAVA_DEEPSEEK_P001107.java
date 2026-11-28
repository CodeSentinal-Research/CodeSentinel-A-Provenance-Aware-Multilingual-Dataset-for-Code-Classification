import java.util.*;

public class Main {
    static int N;
    static ArrayList<Integer>[] graph;
    static int[][] reachability;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine();

        graph = new ArrayList[N];
        reachability = new int[N][N];

        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            String[] edge = scanner.nextLine().split(" ");
            int u = Integer.parseInt(edge[0]) - 1;
            int v = Integer.parseInt(edge[1]) - 1;
            graph[u].add(v);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                reachability[i][j] = dfs(i, j) ? 1 : 0;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(reachability[i][j]);
                if (j != N - 1) {
                    System.out.print(" ");
                } else {
                    System.out.println();
                }
            }
        }
    }

    static boolean dfs(int start, int end) {
        if (start == end) {
            return true;
        }

        for (int neighbour : graph[start]) {
            if (neighbour == end || dfs(neighbour, end)) {
                return true;
            }
        }

        return false;
    }
}
