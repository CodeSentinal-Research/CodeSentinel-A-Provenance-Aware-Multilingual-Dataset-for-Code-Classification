import java.util.*;

public class Main {
    static int V, E, M;
    static ArrayList<ArrayList<Integer>> adj;
    static int[] color;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        V = sc.nextInt();
        E = sc.nextInt();
        M = sc.nextInt();

        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        color = new int[V];

        for (int i = 0; i < E; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        if (isValid()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static boolean isValid() {
        for (int i = 0; i < V; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                if (!dfs(i, 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean dfs(int v, int c) {
        if (color[v] == 0) {
            color[v] = c;
            for (int u : adj.get(v)) {
                if (!dfs(u, -c)) {
                    return false;
                }
            }
        }
        return true;
    }
}
