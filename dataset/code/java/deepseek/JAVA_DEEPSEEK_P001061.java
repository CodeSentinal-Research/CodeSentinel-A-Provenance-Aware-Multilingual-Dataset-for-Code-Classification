import java.util.Scanner;

public class Main {
    static int N, M;
    static int[] parent;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        parent = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            if (findCycle(u, v)) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }

    static boolean findCycle(int u, int v) {
        if (visited[v]) return false;
        if (u == v) return true;
        visited[v] = true;
        if (findCycle(u, parent[v])) {
            return true;
        }
        return false;
    }
}
