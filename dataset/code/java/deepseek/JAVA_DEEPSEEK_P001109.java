import java.util.*;

public class Main {
    static int N, M;
    static int[] colors;
    static ArrayList<Integer>[] graph;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        colors = new int[N + 1];
        graph = new ArrayList[N + 1];
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
            colors[i] = sc.nextInt();
        }
        System.out.println(valid() ? "VALID" : "INVALID");
    }

    static boolean valid() {
        for (int i = 1; i <= N; i++) {
            if (graph[i].size() > 0) {
                int color = colors[i];
                for (int j : graph[i]) {
                    if (colors[j] == color) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
