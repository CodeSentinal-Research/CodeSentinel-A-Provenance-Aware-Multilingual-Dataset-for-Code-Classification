import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int S = scanner.nextInt();
        int T = scanner.nextInt();

        // Create a graph with N nodes and M edges
        int[][] graph = new int[N][N];
        for (int i = 0; i < M; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int capacity = scanner.nextInt();
            graph[u][v] = capacity;
        }

        // Find the minimum cut capacity
        int minCutCapacity = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && graph[i][j] != 0) {
                    int capacity = graph[i][j];
                    int cutCapacity = capacity / 2;
                    if (cutCapacity < minCutCapacity) {
                        minCutCapacity = cutCapacity;
                    }
                }
            }
        }

        // Print the minimum cut capacity
        System.out.println(minCutCapacity);
    }
}
