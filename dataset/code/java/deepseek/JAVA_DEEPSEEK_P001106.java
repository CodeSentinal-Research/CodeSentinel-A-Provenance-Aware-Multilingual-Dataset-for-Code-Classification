import java.util.*;

public class Main {
    static int N, M;
    static List<List<Integer>> graph;
    static int[] indegree;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        graph = new ArrayList<>();
        indegree = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph.get(a).add(b);
            indegree[b]++;
        }
        if (topoSort()) {
            for (int i = 1; i <= N; i++) {
                System.out.print(i + " ");
            }
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }

    public static boolean topoSort() {
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
            for (int neighbour : graph.get(node)) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.add(neighbour);
                }
            }
        }
        return count == N;
    }
}
