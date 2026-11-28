import java.util.*;

public class Main {
    static ArrayList<Integer> graph[];
    static int N, M;
    static int indegree[];
    static Stack<Integer> stack;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        graph = new ArrayList[N + 1];
        indegree = new int[N + 1];
        for (int i = 1; i <= N; i++)
            graph[i] = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph[u].add(v);
            indegree[v]++;
        }
        sc.close();
        for (int i = 1; i <= N; i++)
            if (indegree[i] == 0)
                dfs(i);
        if (stack.size() != N) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        while (!stack.isEmpty())
            System.out.print(stack.pop() + " ");
    }

    static void dfs(int node) {
        for (int neighbour : graph[node]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                dfs(neighbour);
        }
        stack.push(node);
    }
}
