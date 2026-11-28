import java.util.*;
import java.util.stream.IntStream;

public class Main {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        List<Integer>[] graph = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        IntStream.range(0, M).forEach(i -> {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            graph[u].add(v);
        });
        int[] componentCounts = new int[N + 1];
        boolean[] visited = new boolean[N + 1];
        Arrays.fill(componentCounts, 1);
        int stronglyConnectedComponentCount = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, componentCounts);
                stronglyConnectedComponentCount++;
            }
        }
        System.out.println(stronglyConnectedComponentCount);
    }

    private static void dfs(int node, List<Integer>[] graph, boolean[] visited, int[] componentCounts) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, componentCounts);
            }
        }
    }
}
