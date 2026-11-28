import java.util.*;

public class Main {
    static int N, M;
    static ArrayList<Integer>[] graph;
    static int[] indegree;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        graph = new ArrayList[N + 1];
        indegree = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u].add(v);
            indegree[v]++;
        }
        if (topologicalSort() == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public static int topologicalSort() {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        int count = 0;
        while (!q.isEmpty()) {
            int node = q.poll();
            count++;
            for (int neighbour : graph[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.add(neighbour);
                }
            }
        }
        if (count == N) {
            return 1;
        } else {
            return 2;
        }
    }
}
